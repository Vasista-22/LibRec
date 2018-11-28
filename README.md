# LibRec
Library software in C to analyze reference numbers of books and generate the list of reference numbers of those books which are missing from the library

REQUIREMENTS:
1. You need to have the list of reference numbers of books in your library.
2. Also you need to have a computer generated list of accession numbers from your library.

Note: The .txt files provided here are just for your reference of how the reference number lists are expected to be.

USING THE PROGRAMS:

Step1: 
      Compile and run create_lists.c
      
      The following lists would have been generated. 
      1. comp_list.txt    :   having the computer list
      2. withdrawn.txt    :   to be removed from the computer list
      3. accession.txt    :   contaning the original list of accession numbers
      4. physical.txt     :   for now it just contains random numbers
      
      Note: You can make changes to comp_list.txt by adding characters anywhere except at the begining of the file.
      
Step2:
      Compile and run lib.c
      The comp_list.txt gets modified by the removal of withdrawn numbers.
      
Step3:
      Compile and run phase2.c
      Certain accession register numbers which are previously not in comp_list.txt gets added.
      
Step4: 
      Compile and run 3rd_phase.c
      here duplicate removal will be done for physical.txt and missing books from physical.txt gets inserted in a new file caled missing.txt.
      
Note:
     The function of physical.txt is required when you have manually entered the list of reference numbers.
       
