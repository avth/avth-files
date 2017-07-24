/*
 * Selenium Test Cases with TestNG framework
 * ___________________________________________
 * 
 * Automating the reading username, password as parameters from XML file, Logging to the web app and processing the request.
 * This program is run as TestNG Suite.
 * XML file : automationPracticeTestSuite.xml
 * 
 * Revision #1 : 7/24/2017
 * Added random sleep time for thread in "processRequest" method
 */
package com.amsa.testng;
import org.testng.annotations.*;
import org.testng.asserts.SoftAssert;
import org.testng.log4testng.Logger;

import java.util.Random;
import java.util.concurrent.TimeUnit;
import org.openqa.selenium.*;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.interactions.Actions;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.Select;
import org.openqa.selenium.support.ui.WebDriverWait;
import org.testng.Reporter;


public class AutomationPracticeTestNG {
	static WebDriver driver;
	Actions action;
	static WebDriverWait wait;
	SoftAssert softAssert=new SoftAssert();
	
	static final int maxTime=5000;	//	in milliseconds
	static final int minTime=2000;	//	in milliseconds
	static Random generator=new Random();
	int timeToSleep=0;
		
	@BeforeTest
	public void initializations() {
		System.setProperty("webdriver.gecko.driver","C:/geckodriver.exe");
		driver=new FirefoxDriver();
		Reporter.log("Driver Instantiated");
		driver.manage().timeouts().implicitlyWait(1000, TimeUnit.SECONDS);
		wait = new WebDriverWait(driver,10);
		action=new Actions(driver);
	}
	
	@BeforeTest(dependsOnMethods = {"initializations"})
	public void launchBrowser() {
		driver.get("http://www.automationpractice.com/");
		driver.manage().window().maximize();
		driver.findElement(By.xpath(".//*[@id='header']/div[2]/div/div/nav/div[1]/a")).click();
	}
	
	@Test(priority = 0)
	@Parameters({"Username","Password"})
	public void signOn(String Username, String Password) {
		driver.findElement(By.id("email")).sendKeys(Username);
		driver.findElement(By.id("passwd")).sendKeys(Password);
		driver.findElement(By.id("SubmitLogin")).click();
	}
	
	@Test(priority = 1)
	public void processRequest() {
		softAssert.assertEquals(driver.findElement(By.className("logout")).isDisplayed(), driver.findElement(By.className("logout")).isDisplayed(), "logout button found");
		//		click on the women's tab
		driver.findElement(By.xpath(".//*[@id='block_top_menu']/ul/li[1]/a")).click();
		//	click on the dresses checkbox
		driver.findElement(By.xpath(".//*[@id='layered_category_8']")).click();
		//	click on the "in stock" checkbox
		driver.findElement(By.xpath(".//*[@id='layered_quantity_1']")).click();
		//	click on the "new" checkbox
		driver.findElement(By.xpath(".//*[@id='layered_condition_new']")).click();
		//	select the product "lowest first"
		new Select(driver.findElement(By.id("selectProductSort"))).selectByVisibleText("Price: Lowest first");
		//	wait for the page to be refreshed and loaded.
		try { 
			timeToSleep=generator.nextInt(maxTime-minTime) + minTime;
			System.out.println(Thread.currentThread().getStackTrace()[1].getMethodName() + " :" +  timeToSleep);
			Thread.sleep(timeToSleep);  
		} catch(Exception e) {e.printStackTrace(); }	
		action.moveToElement(driver.findElement(By.xpath(".//*[@id='center_column']/ul/li[1]/div/div[1]/div/a[1]/img"))).perform();
		action.moveToElement(driver.findElement(By.xpath(".//*[@id='center_column']/ul/li[1]/div/div[3]/div[1]/a"))).click().perform();
		driver.findElement(By.xpath(".//*[@id='category']/div[2]/div/div/a")).click();
		wait.until(ExpectedConditions.elementToBeClickable(By.xpath(".//*[@id='header']/div[2]/div/div/nav/div[2]/a"))).isDisplayed();
	}
	
	@AfterTest
	public void signOut() {
		driver.findElement(By.xpath(".//*[@id='header']/div[2]/div/div/nav/div[2]/a")).click();
		softAssert.assertAll();
	}
}
