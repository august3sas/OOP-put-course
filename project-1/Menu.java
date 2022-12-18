
import java.util.Scanner;
import java.util.ArrayList;
final public class Menu extends MenuMessageBoard{
    private Scanner sc=new Scanner(System.in);
    private int ind=0;
    public Menu(ArrayList<Train> tl, StationResState s)
    {
        srs=s;
        trainList=tl;
        WelcomeMessage();
        do{
            IndicatorMessage();
            System.out.printf("Enter a number: ");
            ind=sc.nextInt();
            if(ind==5)break;
            try{
                Indicator(ind);
            }
            catch(Exception e){
                e.printStackTrace();
            }
        }while(ind>0&&ind<5);
    }
    
    
    private void Indicator(int in)
    {
        switch(in){
            case 1:
            //System.out.println("t1");
                ReservationMenu();
                break;
            case 2:
                DisplayAllTrains();
                break;
            case 3:
                DisplayAllStations();
                break;
            case 4:
                DisplayInfoTrainFleet();
                break;

            default:
                throw new IllegalArgumentException("Wrong Argument!");
        }
    }
    

}
