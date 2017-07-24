#scenario feature for Maven Cucumber
#Java : StepDefinitions.java
Feature: Web App Sign In
Scenario Outline:	Web App Sign In
	Given I successfully navigate to the url
	Then Enter username as <username>
	And Enter password as <password>
	Then Click submit button
	And Click Women Tab
	And Click Dresses Stock New Checkbox
	And Add Product to wishlist
	Then Check if message is displayed
	Then Sign Out of the app
Examples:
|username|password|
|ab1579@abc.com|abcd1234|
|ab@abc.com|abc1234|