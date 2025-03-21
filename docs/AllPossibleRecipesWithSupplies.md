# AllPossibleRecipesWithSupplies

## Problem Description
You have information about n different recipes. You are given a string array recipes and a 2D string array ingredients. The ith recipe has the name recipes[i], and you can create it if you have all the needed ingredients from ingredients[i]. A recipe can also be an ingredient for other recipes, i.e., ingredients[i] may contain a string that is in recipes.

You are also given a string array supplies containing all the ingredients that you initially have, and you have an infinite supply of all of them.

Return a list of all the recipes that you can create. You may return the answer in any order.

Note that two recipes may contain each other in their ingredients.

## Approach
There is a depedency relationship between the ingredients and the recipes. Some ingredients may be recipes so their ingredients must be available. Since supplies are infinite we can begin by checking what they can make.

This can be reduced to kahns algorithm. Initially the supplies have no dependency so they can be explored first. Whatever recipe is completed by them can be made. We then check what the next layer of recipes we can create with our current available supplies and recipes at this layer.

## Time Complexity
- Time Complexity: O(n + E)
- Space Complexity: O(n)

We visit every node once. and we visit every edge once so O(N + E) where N is the number of ingredients which is recipes + supplies

## Notes
[ANY_ADDITIONAL_NOTES]
