/**
 * 
 */
package kata;

/**
 * @author ${Amsa Easwaran}
 * @created Jun 11, 2018
 */
public class Rectangle extends Shapes implements Resizable {
	
	private double width;
	private double height;
	
	/**
	 * @param sides
	 */
	public Rectangle(double w,double h) {
		super(4);
		this.width = w;
		this.height = h;
		// TODO Auto-generated constructor stub
	}

	/**
	 * 
	 */
	public Rectangle() {
		super();
		// TODO Auto-generated constructor stub
	}

	public double getArea() {
		return width * height;
	}

	/* (non-Javadoc)
	 * @see kata.Shapes#getPerimeter()
	 */
	@Override
	public double getPerimeter() {
		// TODO Auto-generated method stub
		return 2 * (width + height);
	}

	/* (non-Javadoc)
	 * @see kata.Resizable#resize(double)
	 */
	@Override
	public void resize(double x) {
		// TODO Auto-generated method stub
		this.width = x;
	}
}
