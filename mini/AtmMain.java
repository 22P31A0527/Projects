package mini;
import java.util.Scanner;

public class AtmMain {

	private static int status;

	public static void main(String[] args) {
		AtmInterface op = new AtmOperations();
		int atmNumber = 527;
		int atmPin = 527;
		Scanner sc = new Scanner(System.in);
		System.out.println("welcome to ATM Machine!");
		System.out.print("enter atm number: ");
		int atmNumber1 = sc.nextInt();
		System.out.print("enter pin: ");
		int atmPin1 = sc.nextInt();
		if((atmNumber == atmNumber1) && (atmPin == atmPin1))
		{
			while(true)
			{
				System.out.println("1.View Available Balance\n2.Withdraw Amount\n3.Deposit amount\n4.View MiniStatement\n5.exit");
				System.out.println("enter choice :");
				int ch=sc.nextInt();
				if(ch == 1)
				{
					//System.out.println("View Available Balance");
					op.viewBalance();
				}
				else if(ch == 2)
				{
					System.out.println(" Enter amount to withdrawn");
					double withdrawAmount = sc.nextDouble();
					op.withdrawAmount(withdrawAmount);
				}
				else if(ch == 3)
				{
					System.out.println("Enter Amount to Deposit:");
					double depositAmount = sc.nextDouble();   //5000
					op.depositAmount(depositAmount);
				}
				else if(ch == 4)
				{
					op.viewMiniStatement();
					//System.out.println("View MiniStatement");
				}
				else if(ch == 5)
				{
					System.out.println("Please collect your ATM Card\n Thank you for choosing ATM Machine");
					System.exit(0);
				}
				else
				{
					System.out.println("Please enter correct choice");
				}
			}
		}
		else
		{
			System.out.println("incorrect ATM Number or pin");
			System.exit(0);
		}
	}

}
