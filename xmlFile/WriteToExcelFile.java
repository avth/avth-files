package com.amsa.xmlFile;
import com.amsa.xmlFile.ReadXMLFile;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.xssf.usermodel.XSSFSheet;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;

//	class write the data to excel file
public class WriteToExcelFile {
	public static final String file_name="C:\\Users\\IBM_ADMIN\\Desktop\\Amsa\\TECHNOLOGIES\\book_details.xlsx";
	private ReadXMLFile rxf_1;
	private int rowNum, colNum;
	private XSSFWorkbook workbook;
	private XSSFSheet sheet;
	private Row row;
	private Cell cell;
	private ArrayList<ArrayList<String>> listOfLists_1= new ArrayList<ArrayList<String>>();
		
	private String message;
	private boolean headerRowCreated;
	private int headK;
	
		
	File file_w;;
	FileOutputStream fos;
	
	//	constructor
	public WriteToExcelFile() {
		rxf_1=new ReadXMLFile();
		rowNum=colNum=0;
		workbook = new XSSFWorkbook();
		sheet = workbook.createSheet("Sheet1");
		message=" ";
		headerRowCreated=false;
		headK=0;
	}
	
	//	method to create the workBook
	public void createWorkBook() {
		File file_w=new File(file_name);
		try {
			fos=new FileOutputStream(file_w);
			workbook.write(fos);
			System.out.println(" Workbook Created");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}	//	createWorkBook method ends here
	
	//	method to create the header Row
	public void createHeaderRow() {
		List<String> headerRow = new ArrayList<String>();
		headerRow.add("Book ID");
		headerRow.add("Author");
		headerRow.add("Title");
		headerRow.add("Genre");
		headerRow.add("Price");
		headerRow.add("Publish Date");
		headerRow.add("Description");
		
		row= sheet.createRow(rowNum);
		for (headK=0;headK<headerRow.size();headK++) {
			cell=row.createCell(headK);
			cell.setCellValue(headerRow.get(headK));
		}
		
		if (headK==headerRow.size()) {
			message= " Header Row Created";
			headerRowCreated=true;
			rxf_1.printMessage(message);
		}
		else {
			message= " Header Row Not Created";
			headerRowCreated=false;
			rxf_1.printMessage(message);
		}
	}	//	create headerRow method ends here
	
	//	method to write the data to the work book
	public void writeBookList() {
		listOfLists_1=rxf_1.getListOfLists();
					
		for (int l=0;l<listOfLists_1.size();l++) {
			row=sheet.createRow(++rowNum);
			for ( ;(listOfLists_1.get(l)) instanceof ArrayList<?> ; colNum++) {
				if (listOfLists_1.get(l).size()==colNum) {
					colNum=0;
					break;
				}
				cell=row.createCell(colNum);
				cell.setCellValue(listOfLists_1.get(l).get(colNum));
			}	//	inner for loop ends here
		}	//	for loop for listOfLists_1 ends here
	}	//	writeBookList method ends here
}