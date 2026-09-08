An airline company wishes to establish a flight service in a new country. The company wants to provide flight service in such a way that will cover all the cities in the country with a minimum number of flights. Given the coordinates of all the cities in the country, the company has to determine the minimum number of straight routes necessary to cover all the cities. Write an algorithm to help the company find the minimum number of straight routes necessary to cover all the cities.

Input
The first line of the input consists of: two space-separated integers: numCities, representing the number of cities in the country(N). The next N lines consist of two space-separated integers: coordX and coordY representing the X and Y coordinates of the cities, respectively.

Output
Print an integer representing the minimum number of straight routes necessary to cover all the cities.

Constraints
0 <= numCitiess <= 10^4
-100 <= coordX, coordY <= 100

Example
Input:
8
1 4
2 3
2 1
3 2
4 1
5 0
4 3
5 4

Output:
2

Explanation:
The points (2,1)(3,2)((4,3)(5,4) fall on a straight line and the points (1,4)(2,3)(3,2)(4,1)(5,0) fall on another straight line.



  
