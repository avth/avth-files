/**
 * 
 */
package kata;

/**
 * @author ${Amsa Easwaran}
 * @created Jun 11, 2018
 */
public class Triangle extends Shapes {
	double base;
	double side_1;
	double side_2;
	double height;

	int areaOfTri;
	int perimeterOfTri;
	/**
	 * @param sides
	 */
	public Triangle(double s1,double b,double s2,double h) {
		super(3);
		this.base = b;
		this.side_1 = s1;
		this.side_2 = s2;
		this.height = h;
		// TODO Auto-generated constructor stub
	}

	/**
	 * 
	 */
	public Triangle() {
		// TODO Auto-generated constructor stub\
		super();
	}

	/* (non-Javadoc)
	 * @see kata.Shapes#calculateArea()
	 */
	@Override
	public double getArea() {
		// TODO Auto-generated method stub
	return (base + height)/2;
	}

	/* (non-Javadoc)
	 * @see kata.Shapes#calculatePerimeter()
	 */
	@Override
	public double getPerimeter() {
		// TODO Auto-generated method stub
		return side_1 + base + side_2;
	}
}
