# Relations (University Project)
University project, implemented in C++.

##  Description
We have a file with ralations of people, for example "Adam John", they are frinds, for Adam so it will be looking for people wo are frinds with John and at the same time they are not friends with Adam. Every next line in the file is relation like that one in example. When programme starts, we have point the file and click enter twice. The project will fill the file with list of friends of their friends.

## Difficulties with this task:
We cannot work on tables. We are going to open the file and looking on one relation after another relation. 

## Example (- means another line in the file)
File with relations:

-Kasia Andrzej
-Andrzej Tomek
-Tomek Julia
-Julia Zuzanna
-Zuzanna Ola
-Ola Krystian
-Krystian Sara
-Sara Dorian
-Dorian Adam

Final file:

-Kasia Tomek
-Andrzej Julia
-Tomek Kasia Zuzanna
-Julia Andrzej Ola
-Zuzanna Tomek Krystian
-Ola Julia Sara
-Krystian Zuzanna Dorian
-Sara Ola Adam
-Dorian Krystian
-Adam Sara

We are going to focus on Krystian. Krystian is frinds with Ola and Sara. Ola is friends with Zuzanna and Sara is friends with Dorian. So for Krystian friend of his firiends are Zuzanna and Dorian.

## What work: (a person for whom we are creating the list will be called by me/our below)
* Main: 
  * error announcement if the start file does not exist
  * deleting data from helping files 
  * while to opening the file with relations and checkig if the person for whom is creating the list is already put in final file
* function to check if friend of our friend does not repeat himself/herself/themselves next to our name in final file
* function to check if a friend of our firend is not our friend at the same time
* function to connect all the possibilities
* function to choose person for whom we are creating the list
* function to put a friend of our friend next to our name
* function to chceck if person for whom we are creating the list does not repeat himself/herself/themselves in final file
