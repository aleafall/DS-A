# Basis

## 1 Basis
### table
结构化的文件
### 模式（schema）
描述表中的数据信息(存储，分解)

### 列（column）
unit of table.
### 行（row）
a record of table.

### primary key 主键
唯一标识表中每行的这个列（或这几列）称为主键。主键用来表示一个特定的行。

## 2 检索数据
###　2.1 检索单个列
```sql
SELECT prod_name
FROM Products;
```

```
关键字不区分大小写
```


### 2.2 检索多个列
```sql
SELECT prod_id, prod_name, prod_price
FROM Products;
```
### 2.3 检索所有列
```sql
SELECT *
FROM Products;
```

### 2.4 检索不同的值
```sql
SELECT DISTINCT vend_id
FROM Products;
```
选择distinctive的行。不能部分使用.

### 2.5 限制结果

#### 头5行
index begin with 0.
```sql
SELECT TOP 5 prod_name
FROM Products;
```
```sql
SELECT prod_name
FROM Products
FETCH FIRST 5 ROWS ONLY;
```
#### 指定起始索引
`offset`
```sql
SELECT prod_name
FROM Products
LIMIT 5 OFFSET 5;
```

#### 注释
```
--
#
/**/
```

## 排序
### 3.1 排序数据
```
ORDER BY
```
`ORDER BY子句应该放在语句最后`
```sql
SELECT prod_name
FROM Products
ORDER BY prod_name
```
### 3.2 多级排序
```sql
SELECT prod_id, prod_price, prod_name
FROM Products
ORDER BY prod_price, prod_name;
```
### 3.3 按列位置排序
```
SELECT prod_id, prod_price, prod_name
FROM Products
ORDER BY 2, 3;
```
ORDER BY 2，3表示先按prod_price，再按prod_name进行排序。

### 3.4 指定排序方向
降序排列
```
SELECT prod_id, prod_price, prod_name
FROM Products
ORDER BY prod_price DESC;
```
`如果想在多个列上进行降序排序，必须对每一列指定DESC关键字`
`字典序排序中，A与a可能优先级相同`
## 4 过滤(filter)

### 4.1 使用WHERE子句
```
SELECT prod_name, prod_price
FROM Products
WHERE prod_price = 3.49;
```
可使用的操作符
```
BETWEEN 在指定的两个值之间
IS NULL
```

有些操作符不受特定的数据库支持
```
SELECT vend_id, prod_name
FROM Products
WHERE vend_id != 'DLL01';
```
between
```
SELECT prod_name, prod_price
FROM Products
WHERE prod_price BETWEEN 5 AND 10;
```

```
SELECT cust_name
FROM CUSTOMERS
WHERE cust_email IS NULL;
```

## 5 高级数据过滤
### 5.1 组合WHERE子句
`AND`,`OR`
可以加括号，防止出现求值顺序问题
```
SELECT prod_name, prod_price
FROM Products
WHERE (vend_id = 'DLL01' OR vend_id = ‘BRS01’)
AND prod_price >= 10;
```
### 5.2 IN操作符

```
SELECT prod_name, prod_price
FROM Products
WHERE vend_id IN ( 'DLL01', 'BRS01' )
ORDER BY prod_name;
```
### 5.3 NOT非操作符
```
SELECT prod_name
FROM Products
WHERE NOT vend_id = 'DLL01'
ORDER BY prod_name;
```

## 6 通配符过滤
### 6.1 LIKE操作符
使用通配符时要以LIKE开头
####　6.1.1 百分号（%）通配符
`%表示任何字符出现任意次数`
```
SELECT prod_id, prod_name
FROM Products
WHERE prod_name LIKE 'Fish%';
```
Microsoft Access，需要使用*而不是%
'%'不会匹配产品名称为NULL的行
### 6.1.2 下划线（_）通配符
匹配单个字符
DB2不支持通配符_
Microsoft Access，需要使用?而不是_

### 6.1.3 方括号（[ ]）通配符
只能匹配单个字符
```
SELECT cust_contact
FROM Customers
WHERE cust_contact LIKE '[^JM]%'
ORDER BY cust_contact;
```
## 7 计算字段
### 7.1 计算字段

field字段,等同于列
在select语句中创建。

###　7.2 拼接字段
```sql
SELECT vend_name + ' (' + vend_country + ')'
FROM Vendors
ORDER BY vend_name;
```
或是使用`||`.
去掉填充的空格
```
SELECT RTRIM(vend_name) + ' (' + RTRIM(vend_country) + ')'
FROM Vendors
ORDER BY vend_name;
```
别名
这样返回的计算字段没有名字，无法在客户端中使用，需要为其赋予一个别名。
```
SELECT RTRIM(vend_name) + ' (' + RTRIM(vend_country) + ')'
       AS vend_title
FROM Vendors
ORDER BY vend_name;
```
推荐使用别名
### 7.3 算术计算
```
SELECT prod_id,
       quantity,
       item_price,
       quantity*item_price AS expanded_price
FROM OrderItems
WHERE order_num = 20008;
```
支持`+`,`-`,`*`,`/`

## 8　使用函数
### 8.1 函数
sql的函数具有不可移植性
### 8.2 使用函数
#### 8.2.1 文本处理
```
LEFT() 字符串头
LENGTH()
LOWER()
LTRIM()
RIGHT()
RTRIM()
SOUNDEX()       //返回字符串的SOUNDEX值,ms,PostgreSQL不支持
UPPER()
```


#### 8.2.2 日期处理
```
SELECT order_num
FROM Orders
WHERE DATEPART(yy, order_date) = 2012;
```
取date，当yy=2012。
不同的DBMS处理函数迥异。

#### 8.2.3 数值处理
```
ABS()	返回一个数的绝对值
COS()	返回一个角度的余弦
EXP()	返回一个数的指数值
PI()	返回圆周率
SIN()	返回一个角度的正弦
SQRT()	返回一个数的平方根
TAN()	返回一个角度的正切
```

## 9 汇总数据

### 9.1 聚集函数
```
AVG()	返回某列的平均值
COUNT()	返回某列的行数
MAX()	返回某列的最大值
MIN()	返回某列的最小值
SUM()	返回某列值之和
```

用法类似
```
SELECT AVG(prod_price) AS avg_price
FROM Products;
```

### 9.2 聚集不同的值
```
SELECT AVG(DISTINCT prod_price) AS avg_price
FROM Products
WHERE vend_id = 'DLL01';
```
显然不能用于count(*)

## 10 数据分组
### 10.1 创建分组
`GROUP BY`
将结果以分组的形式给出

```
重要
GROUP BY子句可以包含任意数目的列，因而可以对分组进行嵌套，更细致地进行数据分组。
如果在GROUP BY子句中嵌套了分组，数据将在最后指定的分组上进行汇总。换句话说，在建立分组时，指定的所有列都一起计算（所以不能从个别的列取回数据）。
GROUP BY子句中列出的每一列都必须是检索列或有效的表达式（但不能是聚集函数）。如果在SELECT中使用表达式，则必须在GROUP BY子句中指定相同的表达式。不能使用别名。
大多数SQL实现不允许GROUP BY列带有长度可变的数据类型（如文本或备注型字段）。
除聚集计算语句外，SELECT语句中的每一列都必须在GROUP BY子句中给出。
如果分组列中包含具有NULL值的行，则NULL将作为一个分组返回。如果列中有多行NULL值，它们将分为一组。
GROUP BY子句必须出现在WHERE子句之后，ORDER BY子句之前。
```

### 10.2 过滤分组
HAVING 过滤分组，where过滤行
所以必须在分组之后进行
```
SELECT cust_id, COUNT(*) AS orders
FROM Orders
GROUP BY cust_id
HAVING COUNT(*) >= 2;
```

分组后一般也应该排序

### 10.3 SELECT子句顺序
```
子　　句	说　　明	是否必须使用
SELECT	要返回的列或表达式	是
FROM	从中检索数据的表	仅在从表选择数据时使用
WHERE	行级过滤	否
GROUP BY	分组说明	仅在按组计算聚集时使用
HAVING	组级过滤	否
ORDER BY	输出排序顺序	否

```

## 11 子查询
即嵌套查询
### 11.1 使用子查询
```
SELECT cust_id
FROM Orders
WHERE order_num IN (SELECT order_num
                    FROM OrderItems
                    WHERE prod_id = 'RGAN01');
```
子查询只能查询单个列

## 12 联结表
将数据分解为多个组，并减少相同的数据
```
SELECT vend_name, prod_name, prod_price
FROM Vendors, Products
WHERE Vendors.vend_id = Products.vend_id;
```

### 12.1 创建联结
#### 12.1.1 内联结
基于两个表的等值测试
```
SELECT vend_name, prod_name, prod_price
FROM Vendors INNER JOIN Products
 ON Vendors.vend_id = Products.vend_id;
```
#### 12.1.2 联结多个表
```
SELECT prod_name, vend_name, prod_price, quantity
FROM OrderItems, Products, Vendors
WHERE Products.vend_id = Vendors.vend_id
 AND OrderItems.prod_id = Products.prod_id
 AND order_num = 20007;
```

## 13 高级联结
### 13.1 使用表别名
```
SELECT cust_name, cust_contact
FROM Customers AS C, Orders AS O, OrderItems AS OI
WHERE C.cust_id = O.cust_id
 AND OI.order_num = O.order_num
 AND prod_id = 'RGAN01';
```
缩短sql语句,允许在一条SELECT语句中多次使用相同的表。
不返回到客户端.



