/*
 * Selenium Test cases with Maven Cucumber
 * This project build is done in Jenkins.
 * Step Definitions : StepDefinitions.java
 * Feature : loginScenario.feature
 * 
 */

package com.amsa.maven.AutomationPracticeMaven;

import org.junit.runner.RunWith;

import cucumber.api.CucumberOptions;
import cucumber.api.junit.Cucumber;

@RunWith(Cucumber.class)
@CucumberOptions(
			format= {"pretty","html:target/html/","json:target/json/output.json"},
			features = "src/test/resources",
			glue= {"com.amsa.maven.AutomationPracticeMaven"}
)
public class TestRunner {

}