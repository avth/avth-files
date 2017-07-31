#   CREATE HTML PAGES
#   Date    :   7/28/2017

import os
import csv
import time
import webbrowser

#   class HTMLPage
class HTMLPage(object):
    #   initial constructor
    def __init__(self):
        self.csvList=[]
        self.singleRow=[]
        self.fileName=" "
        self.last_name=" "
        self.FONT_SIZE=" "
        self.style_FONT_SIZE=" "

    #   function to read the file name
    def readFileName(self):
        self.fileName=raw_input(" Enter File Name:")
        time.sleep(3)
        self.checkIfFileExists(self.fileName)

    #   checks if the file exists
    def checkIfFileExists(self,fileN):
        print " ",os.getcwd()
        if os.path.isfile(fileN):
            print " ",fileN, " EXISTS"
            self.openReadFile(self.fileName)
        else:
            print " ",fileN, " DOES NOT EXISTS"

    #   if the file EXISTS, open & read the file
    def openReadFile(self,fileN):
        workbook_file=open(fileN,"rU")
        workbook_reader=csv.reader(workbook_file)

        #   read the row and append to the list.
        for row in workbook_reader:
            self.csvList.append(row)

        #   read each row and create HTML File
        for eachRow in self.csvList:
            for eachValue in eachRow:
                self.singleRow.append(eachValue)
            self.createHTMLFile(self.singleRow)
            self.openPage()
            self.singleRow=[]

        #   close the workbook
        workbook_file.close()

    #   create the HTML file
    def createHTMLFile(self,singlyList):
        length_of_list=len(singlyList[0].split())
        first_last_middle_name=singlyList[0].split()
        self.last_name=first_last_middle_name[length_of_list-1]
        
        # append the html extension to the file name
        self.last_name=self.last_name+".html"
        
        #   create the file
        htmlF=open(self.last_name,"w+")
        
        htmlF.write("<html>")
        self.writeNewLine(htmlF)
        i=0
        for values in singlyList:
            self.writeClassToFile(htmlF)
            self.writeNewLine(htmlF)
            self.checkFontSize(i)
            self.writeFontSize(htmlF)
            htmlF.write(values)
            self.writeEndFondEndPara(htmlF)
            self.writeNewLine(htmlF)
            i=i+1
        htmlF.write("</html>")

    #   decide the font size
    def checkFontSize(self,argValue):
        if argValue==0:
            self.FONT_SIZE="7"
            self.style_FONT_SIZE="60pt"
        elif argValue==1:
            self.FONT_SIZE="7"
            self.style_FONT_SIZE="36pt"
        elif argValue==2:
            self.FONT_SIZE="7"
            self.style_FONT_SIZE="36pt"
        elif argValue==3 or argValue==4 or argValue==5 or argValue==6:
            self.FONT_SIZE="6"
            self.style_FONT_SIZE="28pt"

    #   open the page
    def openPage(self):
        webbrowser.open(self.last_name,new=2)

    #   write the class to the file
    def writeClassToFile(self,htmlF):
        htmlF.write("<P CLASS=\"western\" ALIGN=\"CENTER\" STYLE=\"margin-top: 0.08in; margin-bottom: 0.25in\">")

    #   function for writing the new line to the html file
    def writeNewLine(self,htmlF):
        htmlF.write("\n")

    #   function for writing the font size to the html file
    def writeFontSize(self,htmlF):
        htmlF.write("<FONT SIZE=")
        htmlF.write(self.FONT_SIZE)
        htmlF.write(" STYLE=\"font-size:")
        htmlF.write( self.style_FONT_SIZE)
        htmlF.write("\">")

    #   function for writing the end of para
    def writeEndFondEndPara(self,htmlF):
        htmlF.write("</FONT></P>")

#   function main
def main():
    htmlP=HTMLPage()
    htmlP.readFileName()

os.system('cls')
main()
