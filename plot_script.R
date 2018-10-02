library(ggplot2)
mydot <- read.table("dot.txt",header = FALSE) #read the coordinates for the dots
myline <- read.table("line.txt",header = FALSE) #read the coordinates for the lines
myxtics <- read.table("xticks.txt",header = TRUE) #read the x axis ticks
myytics <- read.table("yticks.txt",header = TRUE) #read the y-axis ticks
mycolor <- c("red","blue") #assign the colors to your own color scheme
names(mycolor) <- c("F","R") #name the colors with the forward and reverse codes. F and R should match the first and second color, respectively

myplot <- ggplot(mydot,aes(x = mydot$V1,y=mydot$V2,color=mydot$V3)) + geom_point() #create the ggplot object with the dots
#now create the plot. Parameters can be modified
myplot + geom_segment(data = myline, aes(x=myline$V1,y=myline$V2,xend=myline$V3,yend=myline$V4,color = myline$V5)) + 
  scale_y_continuous(breaks = myytics$ypos,labels = myytics$yname, name = "D. simuulans") +
  scale_x_continuous(breaks = myxtics$xpos,labels = myxtics$xname, name = "D. melanogaster") +
  theme_bw(base_size = 12,base_family = "sans-serif") +
  theme(aspect.ratio =1,legend.position = "none", axis.title.x = element_text(face = "italic"), axis.title.y = element_text(face = "italic")) +
  scale_color_manual(values = mycolor)
