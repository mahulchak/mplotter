# mplotter
Creates a R/ggplot compatible data table from mummerplot output

Often, I like to reproduce mummerplot using ggplot or R graphics. There are several ways to do it. One among them is to create a mummerplot program that creates R compatible data format. But I really like mummerplot and I really don't want to redo what mummerplot already does pretty well. So this is the dirty way I do it. I provide a program that takes mummerplot output and convert into R compatible table. Then I provide an example R script to create a pretty dotplot.

<b>[If you are trying to create a dotplot between two sequences, there is an easier way to use ggplot than this]</b>

 Step 1.
  
  Run mummerplot on your delta file like this -
   ```
    mummerplot [options] --prefix foo --postscript foo.delta
   ```
   
   Here, you can add any option you want. You can add '-filter' or '-layout' or '-fat', basically anything! If you don't add postscript or png option, the dotplot will be created on your screen.
  
  Step 2.
  
  Remove the first three lines from the plot files -
   ```
    tail -n +4 out.fplot > out.new.fplot
    tail -n +4 out.rplot > out.new.rplot
   ```
  Step 3.
  
  Run mplotter on the out.new.fplot and out.new.rplot files.
   ```
   mplotter out.new.fplot out.new.rplot >mydata.txt
   ```
  mydata.txt has 5 columns. First two columns have alignment start coordinates (x1,y1) and the second and the third columns have the alignment end cooridnates (x2,y2). The final column has orientation. A second file is created called "dots.txt" that containes all (x,y) points to create the dots. 
  
  Thoe who are familiar with ggplot can already see where this is going. Here it is -
  
