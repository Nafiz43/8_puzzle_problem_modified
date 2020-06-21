# MODIFIED 8 PUZZLE PROBLEM
In this assignment, my task was to solve the game “Modified 8-puzzle problem” using A*
Search. In this assignment, I was given a 3 x 3 board. The below board is the goal. Here X
Is the blocked position. This tile cannot be moved. A black tile is the empty position, where
Other tiles can be moved. Green tiles are movable tiles. Task was to find the sequence of arrangements:
<table class="tg">
<tbody>
 <tr>
    <td class="tg-0lax">1</td>
    <td class="tg-0lax">2</td>
    <td class="tg-0lax">X</td>
  </tr>

  <tr>
    <td class="tg-0lax">3</td>
    <td class="tg-0lax">4</td>
    <td class="tg-0lax">5</td>
  </tr>
  <tr>
    <td class="tg-0lax">6</td>
    <td class="tg-0lax">7</td>
    <td class="tg-0lax">-1</td>
  </tr>
</tbody>
</table>

Now,                                                                                                             
Considering the current state of the puzzle as follows, the task is to achieve the goal state.
<table class="tg">

<tbody>
  <tr>
    <td class="tg-0lax">7</td>
    <td class="tg-0lax">6</td>
    <td class="tg-0lax">X</td>
  </tr>
  <tr>
    <td class="tg-0lax">4</td>
    <td class="tg-0lax">5</td>
    <td class="tg-0lax">3</td>
  </tr>
  <tr>
    <td class="tg-0lax">-1</td>
    <td class="tg-0lax">2</td>
    <td class="tg-0lax">1</td>
  </tr>
</tbody>
</table>

## Heuristic 1 
Sum of Manhattan distances of the tiles from their goal positions In the given figure, all the tiles except one are out of position, hence for this state, h1 = 1 + 1 +1+2+0+2+1 =8. H1 is an admissible heuristic, since in every move, one tile can only move closer to its goal by one step.
Runtime: 0.9332s

Complexity: O (n^2)

## Heuristic 2
Number of tiles out of row + Number of tiles out of column In the given figure, all the tiles are out of position, hence for this state, h4 = 4 (out of row) + 4(out of column) = 8. H2 is an admissible heuristic, since every tile that is out of column or out of row must be moved at least once and every tile that is both out of column and out of row must be moved at least twice.
Runtime: 1.181s
Complexity: O (n^2)

## Heuristic 3
Number of misplaced tiles In the above figure, all the tiles except one are out of position, hence for this state, h1 = 6 h1 is an admissible heuristic, since it is clear that every tile that is out of position must be moved at least once.
Runtime: 4.548s
Complexity: O (1)	

As all of these are admissible heuristic ,they all give optimal solution but considering time taken for solving the problem ,their performance vary depending on the complexity of heuristic function.

