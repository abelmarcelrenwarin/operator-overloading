#include <iostream>
#include <cmath>

using namespace std;

class PersegiPanjang{
	
	private:
		
		// Member Attribute
		double xmin;
		double xmax;
		double ymin;
		double ymax;
		
		
	public:
		
		// Constructor
		PersegiPanjang(double titikTengah_x, double titikTengah_y, double panjang, double lebar){
			
			this->xmax =  titikTengah_x + panjang / 2; 
			this->xmin =  titikTengah_x - panjang / 2;
			this->ymax =	titikTengah_y + lebar / 2;
			this->ymin =	titikTengah_y - lebar / 2;		
			
		}
		
		void initiate(double xmin, double ymin, double xmax, double ymax){
			
		    this->xmin = xmin;
		    this->ymin = ymin;
		    this->xmax = xmax;
		    this->ymax = ymax;
		    
		}
		
		// Mencari luas dari suatu persegi panjang
		double cariLuas(){
			
			return (xmax - xmin) * (ymax - ymin);
			
		}
		
		// Melakukan printing titik koordinat
		void printCoordinate(){
			
			cout << "xmin: " << xmin << endl;
			cout << "xmax: " << xmax << endl;
			cout << "ymin: " << ymin << endl;
			cout << "ymax: " << ymax << endl;
		}
		
		// Untuk melakukan pengecekan apakah persegi panjang yang diinputkan beririsan
		// Return true bila beririsan
		// Return false bila tidak beririsan
		bool Irisan(PersegiPanjang p){
			
		    // jika salah satu persegi berada diatas persegi lainnya
		    if (this->xmin >= p.xmax || p.xmin >= this->xmax)
		        return false;
		        
		    // jika salah satu persegi berada disebelah kanan persegi lainnya
		    if (this->ymin >= p.ymax || p.ymin >= this->ymax)
		        return false;
		    
			else return true;
		    
		}
		
		bool operator==(PersegiPanjang const& p){
			
		    return this->Irisan(p);
		    
		}
		
		// Menggabungkan kedua persegi panjang apabila kedua persegi panjang saling beririsan
		// dari operator +
		//jika tidak maka akan me-return persegi panjang dengan xmin, ymin, xmax, ymax bernilai 0
		
		PersegiPanjang add(PersegiPanjang p){
			
		    // persegi panjang dengan nilai 0
		    PersegiPanjang temp = PersegiPanjang(0, 0, 0, 0);
		   
		    // Bila beririsan 
		    if (this->Irisan(p))
		    {   
		        //ambil nilai min terkecil dari kedua persegi
		        double minx = (this->xmin < p.xmin) ? this->xmin : p.xmin;
		        double miny = (this->ymin < p.ymin) ? this->ymin : p.ymin;
		        
		        //ambil nilai max terbesar dari kedua persegi
		        double maxx = (this->xmax > p.xmax) ? this->xmax : p.xmax;
		        double maxy = (this->ymax > p.ymax) ? this->ymax : p.ymax;
		        temp.initiate(minx, miny, maxx, maxy);
		    }
		    
		   		return temp;
		    
			}
			
		
		PersegiPanjang operator+(PersegiPanjang const& p){
			
		    return this->add(p);
		    
		}

		
		/*
		 * Mengambil irisan dari kedua persegi panjang (dari operator -)
		 * jika tidak maka akan me-return persegi panjang dengan xmin, ymin, xmax, ymax bernilai 0
		 */
		PersegiPanjang subtract(PersegiPanjang p){
			
		    // persegi panjang dengan nilai 0
		    PersegiPanjang temp = PersegiPanjang(0, 0, 0, 0);
		    // beririsan
		    if (this->Irisan(p)){
		    	
		        //ambil nilai min terbesar dari kedua persegi
		        double minx = (this->xmin > p.xmin) ? this->xmin : p.xmin;
		        double miny = (this->ymin > p.ymin) ? this->ymin : p.ymin;
		        
		        //ambil nilai max terkecil dari kedua persegi
		        double maxx = (this->xmax < p.xmax) ? this->xmax : p.xmax;
		        double maxy = (this->ymax < p.ymax) ? this->ymax : p.ymax;
		        
		        temp.initiate(minx, miny, maxx, maxy);
		    }
		    
		    	return temp;
			}
			
		PersegiPanjang operator-(PersegiPanjang const& p){
			
		    return this->subtract(p);
		    
		}
		
		
		
		 // @brief pre increment overload
		 // menambah luas persegi panjang menjadi dua kali luas sebelumnya
		 // dengan mengalikan panjang dan lebar dengan sqrt(2), dengan nilai titik tengah yang sama
		 
		PersegiPanjang operator++(){
			
		    // hitung nilai tengah
		    double midx = (this->xmin + this->xmax) / 2;
		    double midy = (this->ymin + this->ymax) / 2;
		    
		    // kalikan panjang dan lebar dengan faktor akar 2 tanpa mengubah nilai tengah
		    this->xmin = midx - ((midx - this->xmin) * pow(2, 0.5));
		    this->ymin = midy - ((midy - this->ymin) * pow(2, 0.5));
		    this->xmax = midx + ((this->xmax - midx) * pow(2, 0.5));
		    this->ymax = midy + ((this->ymax - midy) * pow(2, 0.5));
		    
		    PersegiPanjang newP = PersegiPanjang(*this);
		    // karena pre increment, kembalikan nilai baru
		    return newP;
		}
		 
		PersegiPanjang operator++(int){
			
		    // simpan nilai lama
		    PersegiPanjang newP = PersegiPanjang(*this);
		    
		    // gunakan metode pre increment
		    ++(*this);
		    // karena post increment, kembalikan nilai lama
		    return newP;
		}
		
		
		// mengurangi luas persegi panjang menjadi setengah kali luas sebelumnya
		// dengan membagikan panjang dan lebar dengan sqrt(2), dengan nilai titik tengah yang sama
		
		PersegiPanjang operator--(){
			
		    // hitung nilai tengah
		    double midx = (this->xmin + this->xmax) / 2;
		    double midy = (this->ymin + this->ymax) / 2;
		    
		    // bagikan panjang dan lebar dengan faktor akar 2 tanpa mengubah nilai tengah
		    this->xmin = midx - ((midx - this->xmin) / pow(2, 0.5));
		    this->ymin = midy - ((midy - this->ymin) / pow(2, 0.5));
		    this->xmax = midx + ((this->xmax - midx) / pow(2, 0.5));
		    this->ymax = midy + ((this->ymax - midy) / pow(2, 0.5));
		    
		    PersegiPanjang newP = PersegiPanjang(*this);
		    // karena pre decrement, kembalikan nilai baru
		    return newP;
		}
		
		PersegiPanjang operator--(int){
			
		    // simpan nilai lama
		    PersegiPanjang newP = PersegiPanjang(*this);
		    // gunakan metode pre decrement
		    --(*this);
		    // karena post decrement, kembalikan nilai lama
		    return newP;
		}	
	
};


int main(){
	
	cout << "----------------- INPUTKAN VALUE CONSTRUCTOR -----------------" << endl;
	
	double x, y, p, l;
		
	cout << "Masukan koordinat titik tengah, panjang dan tinggi persegi panjang ke-1" << endl;

	cin >> x >> y >> p >> l;
		
	PersegiPanjang p1 = PersegiPanjang(x, y, p, l);
	
	cout << "Masukan koordinat titik tengah, panjang dan tinggi persegi panjang ke-2" << endl;
		
	cin >> x >> y >> p >> l;
		
	PersegiPanjang p2 = PersegiPanjang(x, y, p, l);

	cout << endl << "----------------- MENGECEK APAKAH BERIRISAN -----------------" << endl;
	
	cout << "Persegi panjang 1" << ((p1 == p2) ? "" : " Tidak") << " Beririsan dengan persegi panjang 2" << endl;
		
	cout << endl << "----------------- GABUNGAN / IRISAN -----------------" << endl;
	
	PersegiPanjang gabungan = p1 + p2;
	
	cout << "Persegi panjang 1 dan 2 yang telah digabung memiliki koordinat" << endl;
   	gabungan.printCoordinate();
   	cout << "Dan memiliki luas sebesar: " << gabungan.cariLuas() << " satuan luas" << endl << endl;
   	
   	PersegiPanjang irisan = p1 - p2;
   	
   	cout << "Persegi panjang 1 dan 2 yang telah diiris memiliki koordinat" << endl;
   	irisan.printCoordinate();
   	cout << "Dan memiliki luas sebesar: " << irisan.cariLuas() << " satuan luas" << endl << endl;

	cout << "----------------- OPERATOR (++) DAN (--) ----------------- " << endl;
	
	cout << "Persegi panjang p1 sebelum dilakukan operator ++ adalah: " << endl;
	p1.printCoordinate();
	cout << "Dan memiliki luas sebesar: " << p1.cariLuas() << " satuan luas" << endl << endl;
		
	cout << "Setelah dilakukan operator ++ menjadi: " << endl;
	p1.operator++();
	p1.printCoordinate();
	cout << "Dan memiliki luas sebesar: " << p1.cariLuas() << " satuan luas" << endl << endl;

	cout << "kemudian setelah dilakukan operator -- menjadi: " << endl;
	p1.operator--();
	p1.printCoordinate();
	cout << "Dan memiliki luas sebesar: " << p1.cariLuas() << " satuan luas" << endl << endl;
	
	cout << "Persegi panjang p2 sebelum dilakukan operator ++ adalah: " << endl;
	p2.printCoordinate();
	cout << "Dan memiliki luas sebesar: " << p2.cariLuas() << " satuan luas" << endl << endl;
	
	cout << "Setelah dilakukan operator ++ menjadi: " << endl;
	p2.operator++();
	p2.printCoordinate();
	cout << "Dan memiliki luas sebesar: " << p2.cariLuas() << " satuan luas" << endl << endl;

	cout << "kemudian setelah dilakukan operator -- menjadi: " << endl;
	p2.operator--();
	p2.printCoordinate();
	cout << "Dan memiliki luas sebesar: " << p2.cariLuas() << " satuan luas" << endl << endl;
	
	
	return 0;
}

