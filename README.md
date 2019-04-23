# Group_22

## Topic: Table management system (Tingxiang)

### Problem statement (what problem to solve):

- [*Q1] The system should be able to modify the number of table and the table size according to different time period or season.  (done)
- [*Q2] The system would be able to output the number of table available and the number of customers inside the restaurant.   (done)
- [*Q3] The system should be able to output a 2D image to show which of the table is occupied or available and how many seats of that table is occupied or available.  (done)
- [*Q4] The system would be able read an input of 'release' and 'occupied' and make a new 2D plan image to show which of the table is occupied or available and the situation of the seats immediately . The system will suggestion some tables for users to choose which table they would like to sit. When each table is at least occupied by 1 person,the situation will become 'all_table occupied state'  and the system will automatically assign the extra customers to each table.*The system will not assign or suggest different group of customers sit into same table until all tables is occuiped and become all_table occupied state'. (done)
- [*Q5] The system would be able to read an input of number of a group of customer( n ) and the table they would like to sit and asign them to that table.If the number is larger than the size of the table,the system would remind the user to asign table for (n-table_size) customers until there is no more customer waiting for a table. (done)
- [*Q6] The system should be able to notify the waiter for tables occupied for too long. *The system will notify the waiter how many customer in which table may occupy the table for too long when the restaurant is full or have not enough seats. (done) 
- [Q7] The system should be able to output a number to indicate how many customer is still waiting for a table if the restaurant is full and assign a table to them immediately after one is released.  
- [Q8] The system should be able to assign different number of people into one table (eg. 2 people and 2 people, or 1 person and 3 people) into a four people size table if needed.  (done)


### Problem setting (Reasonable assumptions):  
The system will first read the order that user want to do.
1)Start
2)Setting
3)Staffs
4)Exit
After selecting (1), a 2D image of our restaurant which included table number,Available seats of that table and occupied seats of that table.Then ,the system will read the action that user want to do,release or occupy a table.After reading release and the number of customers, the system will suggest the table numbers that have not been occupied yet.We assume the user should assign the customer to the tables that have not been occupied yet since it is not 'all_table occupied state' yet.If the number of customer is larger than the table size,the system will suggest other table to let the user asign for the rest of the customers.

> 07:00 - 11:30 - Number of table: 6 Table size: 4  
> 11:30 - 14:20 - Number of table: 20 Table size: 5  
> 14:20 - 18:00 - Number of table: 6 Table size: 4  
> 18:00 - 21:30 - Number of table: 20 Table size: 5  

Assume the number of table is 20 and the table size is 4:  
A 2D image should be shown like below:  

> First number indicates which number of table.  
> Second number inducates table size.  
> Third number is the number of occupied seat.
---  
> Program Start

Number of available table: 20  
Number of full table: 0  
Number of available seat: 80  
Number of occupied seat: 0  

> Show 2D image

Table | Table | Table | Table | Table
------------ | ------------- | ------------- | ------------- | -------------
1 (4) [0] | 2 (4) [0] | 3 (4) [0] | 4 (4) [0] | 5 (4) [0]
6 (4) [0] | 7 (4) [0] | 8 (4) [0] | 9 (4) [0] | 10 (4) [0]
11 (4) [0] | 12 (4) [0] | 13 (4) [0] | 14 (4) [0] | 15 (4) [0]
16 (4) [0] | 17 (4) [0] | 18 (4) [0] | 19 (4) [0] | 20 (4) [0]

---

> Input  

Number of customer: _ (eg.4)  
> Output  

Recommendation of table:  
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20  
> They will assign to table 1 automatically.

---

> New Output

Number of available table: 19  
Number of full table: 1  
Number of available seat: 76  
Number of occupied seat: 4  

Table | Table | Table | Table | Table
------------ | ------------- | ------------- | ------------- | -------------
1 (4) [4] | 2 (4) [0] | 3 (4) [0] | 4 (4) [0] | 5 (4) [0]
6 (4) [0] | 7 (4) [0] | 8 (4) [0] | 9 (4) [0] | 10 (4) [0]
11 (4) [0] | 12 (4) [0] | 13 (4) [0] | 14 (4) [0] | 15 (4) [0]
16 (4) [0] | 17 (4) [0] | 18 (4) [0] | 19 (4) [0] | 20 (4) [0]

---

> Until End
