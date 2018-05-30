package kata;

public class NotADecimalNumberException extends Exception {
	
	/**
	 * 
	 */
	private static final long serialVersionUID = -7700334865254188836L;

	public NotADecimalNumberException(String expMsg) {
		super(expMsg);
	}
	
	public void printExceptionMessage(String expMsg) {
		
	}
}
