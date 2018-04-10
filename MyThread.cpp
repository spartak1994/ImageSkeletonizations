//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MyThread.h"
#include "Unit1.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall MyThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------



std::vector<TColor> IntToPixels(std::vector<int > &mas)
{

	std::vector<TColor> vec;

	for(int i =0; i< mas.size(); i++)
	{
		if(mas[i]==0)vec.push_back(clWhite);
		else vec.push_back(clBlack);
	}
	//if(vec[410] == clWhite)ShowMessage("White itp 410"); else ShowMessage("Black itp 410");
	//if(vec[411] == clWhite)ShowMessage("White itp 411"); else ShowMessage("Black itp 411");
	return vec;
}

void FillBitmap(std::vector<int > &mas, TBitmap* output)
{
	output->Canvas->Lock();
	//ShowMessage((UnicodeString)mas[410] + " mas[410]");
	//ShowMessage((UnicodeString)mas[411] + " mas[411]");
	std::vector <TColor> color = IntToPixels(mas);
	//if(color[410] == clWhite)ShowMessage("White fb 410"); else ShowMessage("Black fb 410");
	//if(color[411] == clWhite)ShowMessage("White fb 411"); else ShowMessage("Black fb 411");
	//ShowMessage(output->Width);
	for(int i=0; i<output->Height; i++)
	{
		for(int j=0; j< output->Width; j++)
		{
			output->Canvas->Pixels[j][i] = color[output->Width * i + j];

		}

	}
	//if(output->Canvas->Pixels[26][6]==clWhite)ShowMessage("in fillbitmap White 26");
	//else ShowMessage("in fillbitmapBlack 26");

	//if(output->Canvas->Pixels[27][6]==clWhite)ShowMessage("in fillbitmap White 27");
	//else ShowMessage("in fillbitmapBlack 27");
	color.clear();
	output->Canvas->Unlock();
}

bool CanDelete(int a , int b , int c , int i , int j , int k , int x, int y , int z)
{
	if(a<0) a = 0;
	if(b<0) b = 0;
	if(c<0) c = 0;
	if(i<0) i = 0;
	if(j<0) j = 0;
	if(k<0) k = 0;
	if(x<0) x = 0;
	if(y<0) y = 0;
	if(z<0) z = 0;
	//ShowMessage((UnicodeString)a + " " + b + " " + c + "\n" + i + " " + j + " " + k + "\n" + x + " " + y + " " + z + "\n" );
	int mas[9] = {a,b,c,i,j,k,x,y,z};
	int count = 0;
	for(int hh =0; hh<9; hh++)
	{
		if(hh==4)continue;
		if(mas[hh]==1)count++;
	}
	//ShowMessage((UnicodeString)"count = " + count);
	//теперь рассмотрим случаи
	if(count == 8)
	{
		return true;
	}
	if(count == 7)
	{
		return true;
	}
	if(count==6)
	{
	   if(b==0&&i==0)return false;
	   if(b==0&&k==0)return false;
	   if(i==0&&y==0)return false;
	   if(y==0&&k==0)return false;
	   return true;
	}
	if(count==5)
	{
	   if(a==0&&b==0&&y==0)return false;
	   if(b==0&&c==0&&y==0)return false;
	   if(b==0&&c==0&&i==0)return false;
	   if(c==0&&k==0&&y==0)return false;
	   if(c==0&&i==0&&k==0)return false;
	   if(i==0&&k==0&&z==0)return false;
	   if(b==0&&k==0&&z==0)return false;
	   if(i==0&&y==0&&z==0)return false;
	   if(b==0&&y==0&&z==0)return false;
	   if(b==0&&x==0&&y==0)return false;
	   if(k==0&&x==0&&y==0)return false;
	   if(b==0&&i==0&&x==0)return false;
	   if(i==0&&k==0&&x==0)return false;
	   if(a==0&&i==0&&k==0)return false;
	   if(a==0&&i==0&&y==0)return false;
	   if(b==0&&k==0&&y==0)return false;
	   if(b==0&&k==0&&x==0)return false;
	   if(b==0&&i==0&&k==0)return false;
	   if(i==0&&k==0&&y==0)return false;
	   if(a==0&&k==0&&y==0)return false;
	   if(b==0&&i==0&&y==0)return false;
	   if(c==0&&i==0&&y==0)return false;
	   return true;
	}
	if(count==4)
	{
		if(a==0&&c==0&&i==0&&x==0)return true;
		if(a==0&&c==0&&i==0&&z==0)return true;
		if(c==0&&i==0&&x==0&&y==0)return true;
		if(c==0&&i==0&&x==0&&z==0)return true;
		if(a==0&&b==0&&i==0&&x==0)return true;
		if(a==0&&b==0&&i==0&&z==0)return true;
		if(a==0&&i==0&&x==0&&y==0)return true;
		if(a==0&&i==0&&x==0&&z==0)return true;
		if(i==0&&x==0&&y==0&&z==0)return true;
		if(a==0&&b==0&&c==0&&x==0)return true;
		if(a==0&&b==0&&c==0&&z==0)return true;
		if(b==0&&c==0&&x==0&&z==0)return true;
		if(a==0&&c==0&&x==0&&y==0)return true;
		if(a==0&&c==0&&x==0&&y==0)return true; //крест
		if(a==0&&c==0&&y==0&&z==0)return true;
		if(c==0&&x==0&&y==0&&z==0)return true;
		if(a==0&&b==0&&x==0&&z==0)return true;
		if(a==0&&x==0&&y==0&&z==0)return true;
		if(a==0&&b==0&&c==0&&k==0)return true;
		if(b==0&&c==0&&k==0&&x==0)return true;
		if(b==0&&c==0&&k==0&&z==0)return true;
		if(a==0&&c==0&&k==0&&x==0)return true;
		if(a==0&&c==0&&k==0&&z==0)return true;
		if(c==0&&k==0&&x==0&&z==0)return true;
		if(c==0&&k==0&&y==0&&z==0)return true;
		if(a==0&&k==0&&x==0&&z==0)return true;
		if(a==0&&k==0&&y==0&&z==0)return true;
		if(k==0&&x==0&&y==0&&z==0)return true;
		if(a==0&&b==0&&c==0&&i==0)return true;//добавил

		return false;
	}
	if(count==3)
	{
		if(a==1&&b==1&&c==1)return true;
		if(a==1&&b==1&&k==1)return true;
		if(a==1&&b==1&&i==1)return true;
		if(k==1&&b==1&&c==1)return true;
		if(i==1&&b==1&&c==1)return true;
		if(c==1&&k==1&&z==1)return true;
		if(c==1&&k==1&&y==1)return true;
		if(k==1&&y==1&&z==1)return true;
		if(b==1&&k==1&&z==1)return true;
		if(x==1&&y==1&&z==1)return true;
		if(i==1&&y==1&&z==1)return true;
		if(i==1&&x==1&&y==1)return true;
		if(x==1&&y==1&&k==1)return true;
		if(a==1&&i==1&&x==1)return true;
		if(b==1&&i==1&&x==1)return true;
		if(a==1&&i==1&&y==1)return true;
		if(b==1&&k==1&&y==1)return true;
		if(b==1&&i==1&&k==1)return true;
		if(i==1&&k==1&&y==1)return true;
		if(b==1&&i==1&&y==1)return true;
		return false;
	}
	if(count==2)
	{
		if(a==1&&b==1)return true;
		if(a==1&&i==1)return true;
		if(b==1&&i==1)return true; //8
		if(b==1&&c==1)return true;
		if(c==1&&k==1)return true;
		if(b==1&&k==1)return true; //8
		if(k==1&&z==1)return true;
		if(y==1&&z==1)return true;
		if(k==1&&y==1)return true; //8
		if(x==1&&y==1)return true;
		if(x==1&&i==1)return true;
		if(i==1&&y==1)return true; //8
		return false;
	}
	if(count==1)
	{
		return false;
	}
	if(count==0)
	{
		return false;
	}


}


TBitmap* ResizeB(TBitmap* in, int koef)
{
	in->Canvas->Lock();
	TBitmap* out = new TBitmap();
	out->Canvas->Lock();
	out->Height = in->Height * koef;
	out->Width = in->Width * koef;

	for(int i = 0 ; i<in->Width; i++)
	{
		for(int z=0; z<koef; z++)
		{
			for(int j=0; j< in->Height; j++)
			{
				for(int k=0; k<koef; k++)
				{
					out->Canvas->Pixels[i*koef+z][j*koef+k] = in->Canvas->Pixels[i][j];
				}
			}
		}
	}
	in->Canvas->Unlock();
	out->Canvas->Unlock();



	return out;
}
using std::vector;
__fastcall MyThread::MyThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall MyThread::Execute()
{
	//---- Place thread code here ----

	Form1->bitmap = new TBitmap();
	Form1->output = ResizeB(Form1->bitmap, 1);
	Form1->bitmap->LoadFromFile("input.bmp");
	Form1->input = ResizeB(Form1->bitmap, 4);
	int FormHeight = Form1->bitmap->Height;
	int FormWidth = Form1->bitmap->Width;
	//if(Form1->bitmap->Canvas->Pixels[27][6]==clWhite)ShowMessage("White");
	//else ShowMessage("Black");

	int countOfObhod = 0;
	std::vector<int> vec;
	l2:
	countOfObhod++;
	for(int i = 0; i<FormHeight; i++)
	{
		for(int j = 0; j<FormWidth; j++)
		{
			if(Form1->bitmap->Canvas->Pixels[j][i]==clWhite)vec.push_back(0);
			else vec.push_back(1);
		}
	}
	FillBitmap(vec, Form1->bitmap);
	//ShowMessage(vec[411]);
	//if(Form1->bitmap->Canvas->Pixels[27][7]==clWhite)ShowMessage("White");
	//else ShowMessage("Black");
	Form1->input = ResizeB(Form1->bitmap, 4);
	//ищем левый верхний пиксель
	int X,Y;
	//if(Form1->bitmap->Canvas->Pixels[27][7]==clWhite)ShowMessage("White");
	//else ShowMessage("Black");

	for(int i = 0; i<FormHeight; i++)
	{
		for(int j = 0; j<FormWidth; j++)
		{
			if(Form1->bitmap->Canvas->Pixels[j][i]!=clWhite)
			{
				Form1->bitmap->Canvas->Pixels[j][i] = clRed;
				//ShowMessage("usss") ;
				X = j;
				Y = i;
				goto l1;

			}

		}
	}
	l1:
	ShowMessage((UnicodeString)"X = " + X + " Y = "+ Y);
	//Теперь надо анализировать можно ли удалить этот пиксель или нет
	bool walkContur = true;
	int vx=0;
	int vy=1;
	int nextX;
	int nextY;
	int notDeleteCount = 0;
	while(walkContur)
	{
		int a,b,c,i,j,k,x,y,z;
		if(X==0 && Y==0) //левый верхний угол
		{
			a=-1;
			i=-1;
			x=-1;
			b=-1;
			c=-1;
			j=vec[X+Y*FormWidth];
			k=vec[X+1+Y*FormWidth];
			y=vec[X+(Y+1)*FormWidth];
			z=vec[X+1+(Y+1)*FormWidth];
		}
		else if(X==FormWidth-1 && Y==0) //правый верхний угол
		{
			a=-1;
			b=-1;
			c=-1;
			k=-1;
			z=-1;
			i=vec[X-1+Y*FormWidth];
			j=vec[X+Y*FormWidth];
			x=vec[X-1+(Y+1)*FormWidth];
			y=vec[X+(Y+1)*FormWidth];
		}
		else if(X==0 && Y==FormHeight-1)//левый нижний
		{
			a=-1;
			i=-1;
			x=-1;
			y=-1;
			z=-1;
			b=vec[X+(Y-1)*FormWidth];
			c=vec[X+1+(Y-1)*FormWidth];
			j=vec[X+Y*FormWidth];
			k=vec[X+1+Y*FormWidth];
		}
		else if(X==FormWidth-1 && Y==FormHeight-1) //правый нижний угол
		{
			c=-1;
			k=-1;
			x=-1;
			y=-1;
			z=-1;
			a=vec[X-1+(Y-1)*FormWidth];
			b=vec[X+(Y-1)*FormWidth];
			i=vec[X-1+Y*FormWidth];
			j=vec[X+Y*FormWidth];
		}

		else if(X>0 && X<FormWidth-1 && Y==0)//верхняя сторона
		{
			a=-1;
			b=-1;
			c=-1;
			i=vec[X-1+Y*FormWidth];
			j=vec[X+Y*FormWidth];
			k=vec[X+1+Y*FormWidth];
			x=vec[X-1+(Y+1)*FormWidth];
			y=vec[X+(Y+1)*FormWidth];
			z=vec[X+1+(Y+1)*FormWidth];
		}
		else if(X==FormWidth-1 && Y>0 && Y<FormHeight-1)//правая сторона
		{
		   c=-1;
		   k=-1;
		   z=-1;
		   a=vec[X-1+(Y-1)*FormWidth];
		   b=vec[X+(Y-1)*FormWidth];
		   i=vec[X-1+Y*FormWidth];
		   j=vec[X+Y*FormWidth];
		   x=vec[X-1+(Y+1)*FormWidth];
		   y=vec[X+(Y+1)*FormWidth];
		}
		else if(Y==FormHeight-1 && X>0 && X<FormWidth-1)//нижняя сторона
		{
		   x=-1;
		   y=-1;
		   z=-1;
		   a=vec[X-1+(Y-1)*FormWidth];
		   b=vec[X+(Y-1)*FormWidth];
		   c=vec[X+1+(Y-1)*FormWidth];
		   i=vec[X-1+Y*FormWidth];
		   j=vec[X+Y*FormWidth];
		   k=vec[X+1+Y*FormWidth];
		}
		else if(X==0 && Y>0 && Y<FormHeight-1)//левая сторона
		{
		   a=-1;
		   i=-1;
		   x=-1;
		   b=vec[X+(Y-1)*FormWidth];
		   c=vec[X+1+(Y-1)*FormWidth];
		   j=vec[X+Y*FormWidth];
		   k=vec[X+1+Y*FormWidth];
		   y=vec[X+(Y+1)*FormWidth];
		   z=vec[X+1+(Y+1)*FormWidth];
		}

		else if(X>0 && X<FormWidth-1 && Y>0 && Y<FormHeight-1)//не крайний
		{
		   a=vec[X-1+(Y-1)*FormWidth];
		   b=vec[X+(Y-1)*FormWidth];
		   c=vec[X+1+(Y-1)*FormWidth];
		   i=vec[X-1+Y*FormWidth];
		   j=vec[X+Y*FormWidth];
		   k=vec[X+1+Y*FormWidth];
		   x=vec[X-1+(Y+1)*FormWidth];
		   y=vec[X+(Y+1)*FormWidth];
		   z=vec[X+1+(Y+1)*FormWidth];
		   //ShowMessage(FormWidth);
		   //ShowMessage((UnicodeString)a + " " + b + " " + c + "\n" + i + " " + j + " " + k + "\n" + x + " " + y + " " + z + "\n" );
		}
		bool cd = CanDelete(a,b,c,i,j,k,x,y,z);
		//cd = true;
		if(cd)
		{
			vec[X+Y*FormWidth]=0;
			Form1->bitmap->Canvas->Pixels[X][Y]=clWhite;
			notDeleteCount = 0;
		}
		else
		{
            Form1->bitmap->Canvas->Pixels[X][Y]=clBlack;
			notDeleteCount++;
		}
		//ShowMessage((UnicodeString)"CD = " + cd);
		//теперь пойдем по контуру
		bool isNext = false;

		while(!isNext)
		{
			if(X+vx>0 && X+vx<FormWidth-1 && Y - vy>0 && Y - vy < Form1->bitmap->Height-1)
			{
				if(vec[X+vx+(Y-vy)*FormWidth]==0)
				{
					if(vx==0 && vy==1){vx=1; vy=1; break;}
					if(vx==1 && vy==1){vx=1; vy=0; break;}
					if(vx==1 && vy==0){vx=1; vy=-1; break;}
					if(vx==1 && vy==-1){vx=0; vy=-1; break;}
					if(vx==0 && vy==-1){vx=-1; vy=-1; break;}
					if(vx==-1 && vy==-1){vx=-1; vy=0; break;}
					if(vx==-1 && vy==0){vx=-1; vy=1; break;}
					if(vx==-1 && vy==1){vx=0; vy=1; break;}

				}
				else
				{
					X+=vx;
					Y-=vy;
					//if(vx==0 && vy==1){vx=-1; vy=1; break;}
					if(vx==0 && vy==1){vx=-1; vy=0; break;}

					//if(vx==-1 && vy==1){vx=-1; vy=0; break;}
					if(vx==-1 && vy==1){vx=-1; vy=-1; break;}

					//if(vx==-1 && vy==0){vx=-1; vy=-1; break;}
					if(vx==-1 && vy==0){vx=0; vy=-1; break;}
					//if(vx==-1 && vy==-1){vx=0; vy=-1; break;}
					if(vx==-1 && vy==-1){vx=1; vy=-1; break;}
					//if(vx==0 && vy==-1){vx=1; vy=-1; break;}
					if(vx==0 && vy==-1){vx=1; vy=0; break;}
					//if(vx==1 && vy==-1){vx=1; vy=0; break;}
					if(vx==1 && vy==-1){vx=1; vy=1; break;}
					//if(vx==1 && vy==0){vx=1; vy=1; break;}
					if(vx==1 && vy==0){vx=0; vy=1; break;}
					//if(vx==1 && vy==1){vx=0; vy=1; break;}
					if(vx==1 && vy==1){vx=-1; vy=1; break;}

					isNext = true;
				}
			}
		}
		//walkContur = false;
		FillBitmap(vec, Form1->bitmap);
		Form1->bitmap->Canvas->Pixels[X][Y]=clRed;


		//Form1->input = ResizeB(Form1->bitmap, 4);
		Form1->CanDrawBitmap = true;
		//Form1->CanDrawInput = true;
		//ShowMessage("ok?");
		if(notDeleteCount>=400)
		{
			//vec.clear();

			walkContur = false;
			goto l3;
			//Form1->bitmap->SaveToFile("out.bmp");
            //goto l2;
		}
		 Sleep(StrToInt(Form1->Edit1->Text));

	}
	l3:
	//Form1->input = ResizeB(Form1->bitmap, 4);
	Form1->bitmap->SaveToFile("out.bmp");
    ShowMessage("Скелетизация завершена");
	//Form1->CanDrawBitmap = true;
	//Form1->CanDrawInput = true;

	int M = Form1->bitmap->Height; // размеры
	int N = Form1->bitmap->Width;

	double** distToLeftDown;

	distToLeftDown = new int*[M];
	for (int i = 0; i < M; i++)
		distToLeftDown[i] = new double[N];


	double** distToLeftUp;

	distToLeftUp = new int*[M];
	for (int i = 0; i < M; i++)
		distToLeftUp[i] = new double[N];

	double** distToRightDown;

	distToRightDown = new int*[M];
	for (int i = 0; i < M; i++)
		distToRightDown[i] = new double[N];

	double** distToRightUp;

	distToRightUp = new int*[M];
	for (int i = 0; i < M; i++)
		distToRightUp[i] = new double[N];

}

//---------------------------------------------------------------------------
