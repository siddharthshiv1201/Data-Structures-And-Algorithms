# Write your MySQL query statement below
SELECT product_name, year, price From Sales Left join Product on Sales.product_id=Product.product_id;