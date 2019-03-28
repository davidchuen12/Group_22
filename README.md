# Group_22

## Topic: Table management system (Tingxiang)

### Problem statement (what problem to solve):

- [*Q1] The system should be able to read an input of number of table and an input of table size.  
- [*Q2] The system would be able to output the number of table available and the number of customers inside the restaurant.  
- [*Q3] The system should be able to output a 2D plan image to show which of the table is occupied or available.  
- [*Q4] The system would be able read an input of 'release' and 'occupied' and make a new 2D plan image to show which of the table is occupied or available immediately.  
- [*Q5] The system would be able to read an input of number of a group of customer and suggest a vacant table with minimal enough seats.
- [*Q6] The system should be able to notify the waiter for tables occupied for too long.  
- [Q7] The system should be able to output a number to indicate how many customer is still waiting for a table if the restaurant is full and assign a table to them immediately after one is released.  
- [Q8] The system should be able to assign different number of people into one table (eg. 2 people and 2 people, or 1 person and 3 people) into a four people size table if needed.
- [Q9] If the restaurant is full and a 6 people size is released, the system should be able to make the best assignemnt as a 6 people size table is difficult to be found if the restaureant is full. (The maximum number of customer who can benfit from it to occupy it.) (It is easy to separate 6 indiviual to different people size table but difficult for a group of 6 people to sit together.)  
- [Q10] The system should ask a group of customer (more than 4) willing to be separate into different group or not and give out recommendation of available seats if they answer yes.  


### Problem setting (Reasonable assumptions):  

> 07:00 - 11:30 - Number of table: 10 Table size: 4  
> 11:30 - 14:20 - Number of table: 20 Table size: 5  
> 14:20 - 18:00 - Number of table: 10 Table size: 4  
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
