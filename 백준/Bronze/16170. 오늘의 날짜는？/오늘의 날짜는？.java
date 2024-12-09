import java.time.LocalDate;

public class Main {

	public static void main(String[] args) {
		
		LocalDate now = LocalDate.now();
		System.out.println(now.getYear());
		System.out.println(now.getMonthValue());
		System.out.println(now.getDayOfMonth());
	}
}
