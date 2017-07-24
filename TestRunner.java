/*
 * Automates the login process with Cucumber Framework
 * Feature : scenario.feature
 * Class : AutomationPracCucumber
 */

package com.amsa.cucumber;

import org.junit.runner.RunWith;
import cucumber.api.CucumberOptions;
import cucumber.api.junit.Cucumber;

@RunWith(Cucumber.class)
@CucumberOptions(
		features="Features",
		glue= {"com.amsa.stepDefinitions"}
)
public class TestRunner {

}
