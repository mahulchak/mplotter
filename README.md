# mplotter
Creates publication quality dot plot from using ggplot

While mummerplot is a nice dotplot viewing application, its plots are not of publication quality. To work around this, mummerplot output can be plotted with ggplot or R graphics. There are several ways to do it. Here I describe one such way. I use a program that takes mummerplot output and convert into R compatible table. Then I provide an example R script to create a pretty, publication quality dotplot.
For questions and comments, write to me: mchakrab@uci.edu

<b> Citation</b>: If you find this useful and use it in a paper, please cite <a href="https://www.nature.com/articles/s41588-017-0010-y">this paper</a> which used an early version of this pipeline. 

 Step 1.
  
  Run mummerplot on your delta file like this -
   ```
    mummerplot [options] --prefix foo --postscript foo.delta
   ```
   
   Here, you can add any mummerplot option you want. You can add '-filter' or '-layout' or '-fat', basically anything mummerplot allows! If you don't add postscript or png option, the dotplot will be created on your screen.
  
  Step 2.
  
  Remove the first three lines from the plot files and use the gp file to generate the files for tick labels-
   ```
    tail -n +4 foo.fplot > foo.new.fplot
    tail -n +4 foo.rplot > foo.new.rplot
    sed 's/["|,|\|)|(]//g' foo.gp |tail -n +3 |awk '{if(NF >1)print $1"\t"$2}'|head -n -26 >foo.new.gp

   ```
  Step 3.
  
  Run mplotter on the foo.new.fplot and foo.new.rplot files.
   ```
   mplotter foo.new.fplot foo.new.rplot foo.new.gp
   ```
  mplotter will create 4 files. They are -
  
   1) dot.txt: Contains the x and y coordinates for the dots (alignment start and ends). Also contains the alignment orientation in the final column.

   2) line.txt: Contains 5 columns. First two columns have alignment start coordinates (x1,y1) and the second and the third columns have the alignment end cooridnates (x2,y2). The final column has orientation.

   3) xticks.txt: Contains a table for x ticks positions and labels

   4) yticks.txt: Same as xticks.txt but contains information for the y ticks. 
  
  Thoe who are familiar with ggplot can already see where this is going. Use the example R script "plot_script.R" or create your own R script uisng the data files generated with mplotter. 

 If you have a different example ggplot script or R script, feel free to share it here.
 
 PS: If you are trying to create a dotplot between two sequences, there is an easier way to use ggplot than this. Feel free to write to me to know the trick.
