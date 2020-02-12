## 算法1

DELETE + 自连接

```SQL
delete p1
from person p1, person p2
where p1.email = p2.email   -- 利用where进行自连接
and p1.id > p2.id  -- 选择Id较大的行
```

## 算法2

```SQL
delete from person
where id not in (
    select min_id from
        (select min(id) min_id
        from person
        group by email) as tmp)

```