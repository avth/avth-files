/*
 * Selenium test cases - Cucumber Framework
 * 
 * Feature File: scenario.feature
 * Java File : TestRunner.java
 * 
 */

package com.amsa.stepDefinitions;

import java.util.concurrent.TimeUnit;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.interactions.Actions;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.Select;
import org.openqa.selenium.support.ui.WebDriverWait;

import cucumber.api.java.en.And;
import cucumber.api.java.en.Given;
import cucumber.api.java.en.Then;
import cucumber.api.java.en.When;
import org.junit.Assert;

public class AutomationPracCucumber {
	
	static WebDriver driver;
	static Actions action;
	static WebDriverWait wait;
	
	@Given("^Browser is Open$") 
	public void browser_is_open() throws Throwable {
		System.setProperty("webdriver.gecko.driver","C:/geckodriver.exe");
		driver=new FirefoxDriver();
		action= new Actions(driver);
		driver.manage().timeouts().implicitlyWait(1000, TimeUnit.SECONDS);
		wait = new WebDriverWait(driver,10);
	}
	
	@When("^User Enters \"([^\"]*)\"$")
	public void user_enters_website(String webAddress) throws Throwable {
		driver.get(webAddress);
	}
	
	@Then("^Sign In Link is Displayed$")
	public void sign_in_link_is_displayed() throws Throwable {
		Assert.assertTrue("incorrect", driver.findElement(By.className("login")).isDisplayed());
		driver.findElement(By.className("login")).click();
	}
	
	@Then("^Enter username as ([^\"]*)$")
	public void enter_username(String arg1) throws Throwable {
		driver.findElement(By.id("email")).sendKeys(arg1);
	}
	@And("^Enter password as ([^\"]*)$") 
	public void enter_password(String arg2) throws Throwable {
		driver.findElement(By.id("passwd")).sendKeys(arg2);
	}
	
	@Then("^Click Submit Button$") 
	public void click_submit_button() throws Throwable {
		driver.findElement(By.id("SubmitLogin")).click();
		try {
			Thread.sleep(3000);
		} catch(InterruptedException e) {
			e.printStackTrace();
		}
	}
	
	@And("^Click Women Tab$")
	public void click_women_tab() throws Throwable {
		driver.findElement(By.linkText("Women")).click();
	}
	
	@And("^Click Dresses Stock New Checkbox$")
	public void click_dresses_stock_new_checkbox() throws Throwable {
		driver.findElement(By.id("layered_category_8")).click();
		driver.findElement(By.xpath(".//*[@id='layered_quantity_1']")).click();
		driver.findElement(By.xpath(".//*[@id='layered_condition_new']")).click();
		new Select(driver.findElement(By.id("selectProductSort"))).selectByVisibleText("Price: Lowest first");
		try {
			Thread.sleep(5000);
		} catch(InterruptedException e) {
			e.printStackTrace();
		}
	}
	
	@And("^Add Product to wishlist$")
	public void add_product_to_wishlist() throws Throwable {
		action.moveToElement(driver.findElement(By.xpath(".//*[@id='center_column']/ul/li[1]/div/div[1]/div/a[1]/img"))).perform();
		action.moveToElement(driver.findElement(By.xpath(".//*[@id='center_column']/ul/li[1]/div/div[3]/div[1]/a"))).click().perform();
		System.out.println(driver.findElement(By.className("fancybox-outer")).getText());
	}
	
	@Then("^Check if message is displayed")
	public void check_if_message_is_displayed() throws Throwable {
		Assert.assertEquals(driver.findElement(By.className("fancybox-outer")).getText(),"Added to your wishlist.");
		driver.findElement(By.xpath(".//*[@id='category']/div[2]/div/div/a")).click();
	}
	
	@And("^Signout of the website$")
	public void signout_of_the_website() {
		wait.until(ExpectedConditions.elementToBeClickable(By.xpath(".//*[@id='header']/div[2]/div/div/nav/div[2]/a"))).isDisplayed();
		driver.findElement(By.className("logout")).click();
	}
}	//	class ends here