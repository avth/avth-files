package com.amsa.automationpractice;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Random;
import java.util.concurrent.TimeUnit;

import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.Workbook;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.interactions.Actions;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.Select;
import org.openqa.selenium.support.ui.WebDriverWait;


public class AutomationPractice {
	
	static final int maxTime=5000;	//	in milliseconds
	static final int minTime=2000;	//	in milliseconds
	
	static WebDriver driver;
	Actions action;
	static WebDriverWait wait;
	Workbook wb=null;
	File file;
	FileInputStream inputStream;
	Sheet sheet;
	Row row;
	static Random generator=new Random();
		
	String sheetName="";
	int rowCount=0;
	int timeToSleep=0;
	String fileName="";
	String fileExtensionName="";
	
			
	/*
	 * this method 
	 * 1. sets the property for gecko driver
	 * 2. creates new firefox driver
	 * 3. registers the actions for the driver
	 * 4. gives the file path to read the excel file and sheet.
	 */
	public void initialSettings() {
		System.setProperty("webdriver.gecko.driver", "C:/geckodriver.exe");
		driver=new FirefoxDriver();
		action= new Actions(driver);
		fileName="C:\\Users\\IBM_ADMIN\\Desktop\\Amsa\\userNamePass.xlsx";
		sheetName="Sheet1";
	}
	
	/*
	 * Method reads the excel file.
	 */
	public void readExcelFile() {	
		file = new File(fileName);
		try {
			inputStream=new FileInputStream(file);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		fileExtensionName=fileName.substring(fileName.indexOf("."));
		
		if (fileExtensionName.equals(".xlsx")) {
			try {
				wb=new XSSFWorkbook(inputStream);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		if (fileExtensionName.equals(".xls")) {
			try {
				wb=new HSSFWorkbook(inputStream);
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		sheet=wb.getSheet(sheetName);
		//	gets the number of rows present in the sheet
		rowCount=sheet.getLastRowNum()-sheet.getFirstRowNum();
	}
	
	/*
	 * Method launches the website and maximizes the window 
	 */
	public void launchTheWebsite() {
		driver.get("http://www.automationpractice.com/");
		driver.manage().window().maximize();
		//	click on "Sign In"
		driver.findElement(By.xpath(".//*[@id='header']/div[2]/div/div/nav/div[1]/a")).click();
	}
	
	/*
	 * This method signs on the website reading username and password from the excel file.
	 * After processing the request for the particular user, the user is signed out and the next
	 * user (if any) is signed in and request processed.
	 */
	public void signIn() {
		for (int i=0;i<rowCount;) {
			row=sheet.getRow(++i);
			launchTheWebsite();
			for(int j=0;j<row.getLastCellNum()-1;) {
				driver.findElement(By.id("email")).sendKeys(row.getCell(j).getStringCellValue());
				driver.findElement(By.id("passwd")).sendKeys(row.getCell(++j).getStringCellValue());
				driver.findElement(By.id("SubmitLogin")).click();
				try {	
					timeToSleep=generator.nextInt(maxTime-minTime) + minTime;
					System.out.println(Thread.currentThread().getStackTrace()[1].getMethodName() + " :" +  timeToSleep);
					Thread.sleep(timeToSleep);
				} catch(Exception e) {e.printStackTrace(); }
				processRequest();
				signOut();
			}
		}
	}
	
	/*
	 * request is processed. 
	 */
	public void processRequest() {
		//	click on the women's tab
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
	
	/* 
	 * the user is signed out
	 */
	public void signOut() {
		driver.findElement(By.xpath(".//*[@id='header']/div[2]/div/div/nav/div[2]/a")).click();
		try { 
			timeToSleep=generator.nextInt(maxTime-minTime) + minTime;
			System.out.println(Thread.currentThread().getStackTrace()[1].getMethodName() + " :" +  timeToSleep);
			Thread.sleep(timeToSleep);
		} catch(Exception e) {e.printStackTrace(); }
	}

	/*
	 * main method
	 */
	public static void main(String[] args) {
		//	create an object for the class
		AutomationPractice ap = new AutomationPractice();
		//	call the method "initialSettings"
		ap.initialSettings();
		ap.readExcelFile();
		driver.manage().timeouts().implicitlyWait(1000, TimeUnit.SECONDS);
		wait = new WebDriverWait(driver,10);
		ap.signIn();
		driver.quit();
	}
}