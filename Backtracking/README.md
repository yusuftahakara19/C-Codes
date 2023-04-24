 <hr>
<h2> PROBLEM </h2>
On an NxN game board, N colors are placed in different order on each line. The order of the colors in a row can be changed by moving the colors circularly to the right. For example, if the colors in the row are red, blue, green, and purple, the new order will be purple, red, blue, green when the row is moved to the right 1 time. If it is shifted to the right one more time, green, purple, red, blue are obtained. In the last case, design the algorithm that recursively organizes the game board with the backtracking method so that there is only 1 of each color in each column.

<h2> SOLUTION </h2>
<em><strong>Colors</strong></em> <br>
I created a struct to give each color an index. Since the N value given to us in the question is maximum 8, I created a dynamic array with 8 colors and placed the colors as their indexes and rows in the array.

<em><strong>One of each color in each column</strong></em> <br>
I used the backtracking method for this. When using this method, if there is a repeating color in a column, I did a circular right shift and checked the new status. If the colors in a row cannot be shifted so that they are not the same color in the same column, I recursively use the backtracking method to shift the colors in the next row. After doing this for all rows, if there is no repeating color in a column, I terminate the function.
<hr>



![1](https://user-images.githubusercontent.com/119736588/233837249-43b60524-c69f-4dca-b13f-f20bbfbccba2.PNG)
![2](https://user-images.githubusercontent.com/119736588/233837250-af1a35b7-447f-4810-8c23-becf1439d81f.PNG)
![3](https://user-images.githubusercontent.com/119736588/233837255-3dde0ddb-ff98-418e-8a0b-dedb3fc09114.PNG)
![4](https://user-images.githubusercontent.com/119736588/233837256-5fcfbe4e-84d5-4465-8bc7-dc1eacdfc4d1.PNG)
![5](https://user-images.githubusercontent.com/119736588/233837258-674ad2fa-dc21-49e6-9e6f-936ed83746c1.PNG)
![6](https://user-images.githubusercontent.com/119736588/233837260-77b3e93c-7e22-4b11-aa0a-e90bb3e2109c.PNG)
![7](https://user-images.githubusercontent.com/119736588/233837265-81d31e53-9565-441b-9ace-3fe1f983c3d2.PNG)
