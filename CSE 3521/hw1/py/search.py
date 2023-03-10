"""
In search.py, you will implement generic search algorithms which are called
by Pacman agents (in searchAgents.py).
""" 

import util
from util import heappush, heappop
class SearchProblem:
    """
    This class outlines the structure of a search problem, but doesn't implement
    any of the methods (in object-oriented terminology: an abstract class).

    You do not need to change anything in this class, ever.
    """

    def getStartState(self):
      """
      Returns the start state for the search problem
      """
      util.raiseNotDefined()

    def isGoalState(self, state):
      """
      state: Search state

      Returns True if and only if the state is a valid goal state
      """
      util.raiseNotDefined()

    def getSuccessors(self, state):
      """
      state: Search state

      For a given state, this should return a list of triples,
      (successor, action, stepCost), where 'successor' is a
      successor to the current state, 'action' is the action
      required to get there, and 'stepCost' is the incremental
      cost of expanding to that successor
      """
      util.raiseNotDefined()

    def getCostOfActions(self, actions):
      """
      actions: A list of actions to take

      This method returns the total cost of a particular sequence of actions.  The sequence must
      be composed of legal moves
      """
      util.raiseNotDefined()


def tinyMazeSearch(problem):
    """
    Returns a sequence of moves that solves tinyMaze.  For any other
    maze, the sequence of moves will be incorrect, so only use this for tinyMaze
    """
    from game import Directions
    s = Directions.SOUTH
    w = Directions.WEST
    return  [s,s,w,s,w,w,s,w]

def depthFirstSearch(problem):
    """
    Search the deepest nodes in the search tree first.
    Your search algorithm needs to return a list of actions that reaches
    the goal. Make sure that you implement the graph search version of DFS,
    which avoids expanding any already visited states. 
    Otherwise your implementation may run infinitely!
    To get started, you might want to try some of these simple commands to
    understand the search problem that is being passed in:
    print("Start:", problem.getStartState())
    print("Is the start a goal?", problem.isGoalState(problem.getStartState()))
    print("Start's successors:", problem.getSuccessors(problem.getStartState()))
    """
    """
    YOUR CODE HERE
    """

    visited = []
    openset = util.Stack()
    openset.push((problem.getStartState(), []))
    
    while not openset.isEmpty():
      (state, actions) = openset.pop()

      if problem.isGoalState(state):
        return actions

      if state not in visited:
        visited.append(state)

        for successor in problem.getSuccessors(state):
          successor_actions = list(actions)
          successor_actions.append(successor[1])
          openset.push((successor[0], successor_actions))
          
    util.raiseNotDefined()
    

def breadthFirstSearch(problem):
    """
    YOUR CODE HERE
    """

    visited = []
    openset = util.Queue()
    openset.push((problem.getStartState(), []))

    while not openset.isEmpty():
      (state, actions) = openset.pop()

      if problem.isGoalState(state):
        return actions
      
      if state not in visited:
        visited.append(state)

        for successor in problem.getSuccessors(state):
          successor_actions = list(actions)
          successor_actions.append(successor[1])
          openset.push((successor[0], successor_actions))

    util.raiseNotDefined()

def uniformCostSearch(problem):
    """
    YOUR CODE HERE
    """

    visited = []
    openset = []
    heappush(openset, (0, (problem.getStartState(), [])))

    while len(openset) > 0:
      (state, actions) = heappop(openset)[1]
      
      if problem.isGoalState(state):
        return actions
      
      if state not in visited:
        visited.append(state)

        for successor in problem.getSuccessors(state):
          successor_actions = list(actions)
          successor_actions.append(successor[1])

          cost = problem.getCostOfActions(successor_actions)
          heappush(openset, (cost, (successor[0], successor_actions)))

    util.raiseNotDefined()

def nullHeuristic(state, problem=None):
    """
    A heuristic function estimates the cost from the current state to the nearest
    goal in the provided SearchProblem.  This heuristic is trivial.
    """
    return 0

def aStarSearch(problem, heuristic=nullHeuristic):
    """
    YOUR CODE HERE
    """

    visited = []
    openset = util.PriorityQueue()
    h_start = heuristic(problem.getStartState(), problem)
    openset.push((problem.getStartState(), []), h_start)

    while not openset.isEmpty():
      (state, actions) = openset.pop()
      
      if problem.isGoalState(state):
        return actions
      
      if state not in visited:
        visited.append(state)

        for successor in problem.getSuccessors(state):
          successor_actions = list(actions)
          successor_actions.append(successor[1])

          cost = problem.getCostOfActions(successor_actions)
          dist = heuristic(successor[0], problem)
          openset.push((successor[0], successor_actions), cost + dist)
          openset.update((successor[0], successor_actions), cost + dist)

    util.raiseNotDefined()

# Abbreviations
bfs = breadthFirstSearch
dfs = depthFirstSearch
astar = aStarSearch
ucs = uniformCostSearch