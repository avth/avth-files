package com.amsa.xmlFile;

import com.amsa.xmlFile.WriteToExcelFile;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

import org.w3c.dom.*;
import org.xml.sax.SAXException;

import javax.xml.parsers.*;

//	class reads the xml file
public class ReadXMLFile {
	Scanner input;
	File file;
	Document doc;
	Element root;
	DocumentBuilderFactory factory=DocumentBuilderFactory.newInstance();
	DocumentBuilder builder;
	NodeList nodeL;
	
	private static ArrayList<ArrayList<String>> listOfLists= new ArrayList<ArrayList<String>>();
	private ArrayList<String> singlyList;
	private static int sizeOfLL, sizeOfSL;
	private String message;
	private boolean fileParsed;
	
	//	constructor
	public ReadXMLFile() {
		sizeOfLL=sizeOfSL=0;
		message=" ";
		fileParsed=false;
	}
	
	//	returns the list
	public ArrayList<ArrayList<String>> getListOfLists() {
		return listOfLists;
	}
	
	//	returns the size of the list
	public int sizeOfListOfLists() {
		return sizeOfLL;
	}
	
	//	returns the size of the singly list
	public int sizeOfSinglyList() {
		return sizeOfSL;
	}
	
	//	method reads the file name
	public void readFileName() {
		try {
			System.out.println(" Enter file name :");
			input= new Scanner(System.in);
			file=new File(input.nextLine());
			input = new Scanner(file);
		} catch (FileNotFoundException f) {
			f.printStackTrace();
		}
	}
	
	//	method to parse the xml file and retrieve the root element
	public void getRootElement() {
		try {
			builder=factory.newDocumentBuilder();
			doc=builder.parse(file);
			fileParsed=true;
		} catch (ParserConfigurationException | SAXException | IOException e) {
			e.printStackTrace();
		}
		root=doc.getDocumentElement();
		if (fileParsed==true) {
			message=" The root element is :" + root;
			printMessage(message);
			//System.out.println(" The root element is :" + root);
		}
	}
	
	//	method to retrieve the nodes list and the tag name
	public void getNodeList() {
		nodeL=doc.getElementsByTagName("book");
		printMessage("----------------------------------");
		for (int i=0;i<nodeL.getLength();i++) {
			try {
				Node nNode=nodeL.item(i);
				singlyList = new ArrayList<String>();
				if (nNode.getNodeType()==Node.ELEMENT_NODE) {
					Element nodeItem=(Element)nNode;
					String bookId=nodeItem.getAttribute("id");
					String author=nodeItem.getElementsByTagName("author").item(0).getTextContent();
					String title=nodeItem.getElementsByTagName("title").item(0).getTextContent();
					String genre=nodeItem.getElementsByTagName("genre").item(0).getTextContent();
					String price=nodeItem.getElementsByTagName("price").item(0).getTextContent();
					String publish_date=nodeItem.getElementsByTagName("publish_date").item(0).getTextContent();
					String description=nodeItem.getElementsByTagName("description").item(0).getTextContent();
					singlyList.add(bookId);
					singlyList.add(author);
					singlyList.add(title);
					singlyList.add(genre);
					singlyList.add(price);
					singlyList.add(publish_date);
					singlyList.add(description);
					listOfLists.add(singlyList);
				}
			} catch (Exception e) {e.printStackTrace();}
		}
	}
	
	//	method to print the list
	public void printList() {
	}
	
	//	method to print the message
	public void printMessage(String message) {
		System.out.println(message);
	}

	//	main method
	public static void main(String[] args) {	
		ReadXMLFile rxf= new ReadXMLFile();
		WriteToExcelFile excelFile = new WriteToExcelFile();
		rxf.readFileName();
		rxf.getRootElement();
		rxf.getNodeList();
		rxf.printList();
		excelFile.createHeaderRow();
		excelFile.writeBookList();
		excelFile.createWorkBook();
	}
}