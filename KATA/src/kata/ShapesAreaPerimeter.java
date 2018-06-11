/**
 * 
 */
package kata;
import kata.Rectangle;
import kata.Triangle;
import kata.Shapes;

/**
 * @author ${Amsa Easwaran}
 * @created Jun 11, 2018
 */
public class ShapesAreaPerimeter {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Rectangle rect = new Rectangle(2,3);
		System.out.println("Reactangle Side : " + " " + rect.getNumSides() + " ,Area : " + rect.getArea() 
		+ " " + "Perimeter : " + rect.getPerimeter());
		rect.resize(4);
		System.out.println("Reactangle Side : " + " " + rect.getNumSides() + " ,Area : " + rect.getArea() 
		+ " " + "Perimeter : " + rect.getPerimeter());
		
		Triangle tri = new Triangle(3,2,2,3);
		System.out.println("Triangle Side : " + " " + tri.getNumSides() + " ,Area : " + tri.getArea() 
		+ " " + "Perimeter : " + tri.getPerimeter());
		
		/*
		 * Create an array of Shapes.
		 */
		Shapes[] sh = new Shapes[2];
		sh[0] = new Rectangle();
		sh[1] = new Triangle();
		
		for(int i=0;i<sh.length;i++) {
			Shapes s = sh[i];
			if (s instanceof Rectangle) {
				sh[i] = new Rectangle(4,5);
				System.out.println("Reactangle Side : " + " " + sh[i].getNumSides() + " ,Area : " + sh[i].getArea() 
				+ " " + "Perimeter : " + sh[i].getPerimeter());
			} else if (s instanceof Triangle) {
				sh[i] = new Triangle(4,5,6,7);
				System.out.println("Triangle Side : " + " " + sh[i].getNumSides() + " ,Area : " + sh[i].getArea() 
				+ " " + "Perimeter : " + sh[i].getPerimeter());
			}
		}
	}
}
