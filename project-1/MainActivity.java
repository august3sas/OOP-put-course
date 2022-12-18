import java.util.ArrayList;
import java.util.Random;
public class MainActivity {
    public static void main(String[] args)
    {
        Random rand=new Random();
        ArrayList<Train>Trains=new ArrayList<Train>();
        Train Sredzianin = new Train(77774,"Sredzianin","Classic",1,28,5);
        Train Yoshida = new Train(77734,"Yoshida","EZT",28,1,4);
        Train Andrut = new Train(77777,"Andrut","EZT",1,28,3);
        Trains.add(Sredzianin);
        Trains.add(Yoshida);
        Trains.add(Andrut);
        StationResState TrainStateAtEachStation=new StationResState(Trains,28);
            //System.out.println(1);
        for(int i=0;i<Trains.size();i++)
        {
            //System.out.println("APS: "+Trains.get(i).allPossibleSeats);
            int randreserv=rand.nextInt(Trains.get(i).allPossibleSeats);
            //System.out.println("RR: "+randreserv);
            for(int j=0;j<randreserv;j++)
            {
                //System.out.println(4);
                GeneratedReservation test=new GeneratedReservation(TrainStateAtEachStation,i);
                TrainStateAtEachStation=test.StatesWithNewReservation();
                //System.out.println(5);
            }
        }
        //System.out.println(6);
        //TrainStateAtEachStation.debug1();
        /*for(int i=0;i<180;i++)
        {
            GeneratedReservation test=new GeneratedReservation(Trains.get(0));
            Trains.set(0,test.WithNewReservation());
        }
        //System.out.println("PO REZERWACJI");
        //Trains.get(0).DisplayCars();
        for(int i=0;i<120;i++)
        {
            
            GeneratedReservation test=new GeneratedReservation(Trains.get(1));
            Trains.set(1,test.WithNewReservation());
        }*/
        //Trains.get(1).DisplayCars();
        Menu menu = new Menu(Trains, TrainStateAtEachStation);
        //System.out.println(menu.stationBase.returnIndexOfElement("Kepno"));

    }
}