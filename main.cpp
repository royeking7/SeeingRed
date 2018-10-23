#include "Bitmap/bitmap.h"
#include <iostream>
#include <vector>

using namespace std;

//argc - number of arguments in command
//argv - each argument word, stored in an array
int main(int argc, char* argv[])

{
  string filename;
  Bitmap image;

  if(argc!=2)
  {
    cout<<"Please specify one image file!\n";
  }

  if(argc==2)
  { 
    filename = argv[1];
    image.open(filename);
  }

  if(image.isImage()== false)
  {
    cout<<"Image file must be a bitmap with 24-bit color depth.\n";
  }

  if(image.isImage()== true)
  {
    vector <vector<Pixel> >imagePixels = image.toPixelMatrix();
    cout<<filename<<" is "<<imagePixels.size()<<" pixel high and "<<imagePixels[0].size()<<" wide "<<endl;

    for (int row=0; row<imagePixels.size(); row++)
    {
      for (int column=0; column<imagePixels[0].size(); column++)
      {
        Pixel color; 
        color = imagePixels[row][column];
        color.green=0;
        color.blue=0;
        imagePixels[row][column]=color;
      }
    }
    image.fromPixelMatrix(imagePixels);
    image.save("redness.bmp");



  }
  return 0;
}
