# Group_22

Topic: Table management system (Tingxiang)

problem statement(what problem to solve):

*Q1.  The system should be able to read an input of number of table and an input of table size.  
*Q2.  The system would be able to output the number of table available and the number of customers inside the restaurant.  
*Q3.  The system should be able to output a 2D plan image to show which of the table is occupied or available.  
*Q4.  The system would be able read an input of 'release' and  ' occupied' and make a new 2D plan image to show which of the table is occupied or available immediately.  
*Q5.  The system would be able to read an input of number of a group of customer and  suggest a vacant table with minimal enough seats  
*Q6.  The system should be able to  notify the waiter for tables occupied for too long.  
Q7.   The system should be able to output a number to indicate how many customer is still waiting for a table if the restaurant is full and assign a table to them immediately after one is released.  
Q8.   The system should be able to assign different number of people into one table(eg.2 people and 2 people,or 1 person and 3 people)into a four people size table if needed.  
Q9.   If the restaurant is full and a 6 people size is released,the system should be able to make the best assignemnt as a 6 people size table is difficult to be found if the restaureant is full.(the maximum number of customer who can benfit from it to occupy it)(it is easy to separate 6 indiviual to different people size table but difficult for a group of 6 people to sit together).  
Q10.  The system should ask a group of customer (more than 4) willing to be separate into different group or not and give out recommendation of available seats if they answer yes.  


problem setting( reasonable assumptions):  

Assume number of table is 20 and the table size is 4:  
A 2D image should be shown like below:  
======================================  
口(4)   口(4)   口(4)   口(4)   口(4)(*table and table size)
1       2       3       4       5   (*number of table)
口(4)   口(4)   口(4)   口(4)   口(4)
6       7       8       9      10
口(4)   口(4)   口(4)   口(4)   口(4)
11      12      13     14      15
口(4)   口(4)   口(4)   口(4)   口(4)
16      17      18     19      20
======================================  
Number of available seat:20
Number of occupied seat:0
======================================
Number of customer:_(eg.4)
Recommendation of table:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

