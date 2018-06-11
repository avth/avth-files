/**
 * Abstract classes & Interfaces
 */
package kata;

/**
 * @author ${Amsa Easwaran}
 * @created Jun 11, 2018
 */
public abstract class Shapes {
	int numSides;
	
	public Shapes (int sides) {
		numSides = sides;
	}
	
	/**
	 * 
	 */
	public Shapes() {
		// TODO Auto-generated constructor stub
	}

	public int getNumSides() {
		return numSides;
	}
	
	public abstract double getArea();
	public abstract double getPerimeter();
}