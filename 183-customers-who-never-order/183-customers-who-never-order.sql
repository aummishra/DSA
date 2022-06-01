# Write your MySQL query statement below
SELECT name as 'Customers'
from Customers
where id Not in (
 select customerId from Orders
);