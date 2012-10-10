Friend-of-Friend-Algorithm
==========================

A Networking Site Friend Recommendation Program Using Friends of Friends Algorithm.
For each user a node is created and for each friend request links are added for that node.
Then we find friend recommendation for a particular user.
All the user are identified by a slno.
For the sample data there are 6 users.
For each user there is a slno
A->1
B->2
C->3
D->4
E->5
F->6

Now,what this program do is find friend recommendation for a particular user
Step 1: We input that user slno
Step 2: We look that user node,see all its friends
Step 3: For all its friends we see its adjacency list and include friend in recommendation except those that are already friends with user
Step 4: We increment count for each user
Step 5: Then we display the recommendation 
