 <hr>
<h2> PROBLEM </h2>
In this assignment, you are asked to develop an algorithm that detects people who are influencers in a social network. When designing your algorithm, use DFS and/or BFS algorithms where necessary.

There are different methods of detecting influencers on a social network. Two of these methods will be used in this assignment. In the directional graph given, the nodes show the names and surnames of the people, and the directional links show the links to the people that the person follows. This graph
The steps to be done on it are as follows:
1. When finding which nodes in a graph belong to influencer people, it is necessary to calculate for each node. But, especially in a large network, it will be unnecessary waste of time to trade for people with few followers. To eliminate nodes with no potential to become influencers, write the function that does the following:
Eliminate nodes whose in-degree value is less than a given M value by calculating the in-degree value of the nodes. After elimination, also eliminate nodes whose in-degree value falls below M. Repeat this process until there are no nodes with an in-degree value below M.
2. Write a function that calculates the total number of direct and indirect connections to a node for nodes not eliminated in step 1. For example, in the example below, apart from the direct connections to node 3 from nodes 4 and 5, there are a total of 4 connections from nodes 0, 4, 5 and 6 due to connections 0-5-3 and 0-6-4-3.

<h2> SOLUTION </h2>
<em><strong>Elimination of nodes with in-degree value less than M</strong></em> <br>
Of the nodes in the graph, the nodes with in-degree value less than M
All nodes will be visited in order to perform the elimination. During the elimination process, other nodes followed by the node will also be visited and the in-degree values of these followed nodes will be reduced by 1.
It will delete the element from the array and the array will be set to no spaces.
The elimination process will continue until there are no nodes below M.

<em><strong>Calculation of the total number of direct and indirect connections to the node</strong></em> <br>
BFS algorithm can be used for this process. For this, the following steps should be followed
We will select the starting node and start scanning that node. We will check if the node is following and add the following nodes to the queue. We will select the first node in this list of nodes and continue scanning this node. We will continue this process as long as our head value is less than our tail value. The point we need to pay attention to here is that this graph is a directional graph, so we should check the existence of our node in the follow sequence of the linked node.
<hr>



![2](https://user-images.githubusercontent.com/119736588/233901770-e72d60ba-20c4-4915-b8b4-5a218a20ef76.PNG)






