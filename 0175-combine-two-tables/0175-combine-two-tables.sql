# Write your MySQL query statement below

select p.firstName,p.lastName,A.city,A.state from person p
left join Address A on p.personID = A.personId;
