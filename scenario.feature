# scenario.feature for AutomationPracCucumber.java
Feature: Launch Website
Scenario Outline:	Open Site
	Given Browser is Open
	When User Enters "http://automationpractice.com"
	Then Sign In Link is Displayed
	Then Enter username as <username>
	And Enter password as <password>
	Then Click Submit Button
	And Click Women Tab
	And Click Dresses Stock New Checkbox
	And Add Product to wishlist
	Then Check if message is displayed
	And Signout of the website
Examples:
|username|password|
|ab1579@abc.com|abcd1234|
|ab@abc.com|abc1234|