
import java.util.ArrayList;
public class StationResState {
    public ArrayList<ArrayList<Train>>trainState=new ArrayList<ArrayList<Train>>();
    //--ACCESS_IDENTIFIER-------station_number----------train_iterator---------///
    public StationResState(ArrayList<Train>t,int statnum)
    {
        for(int i=0;i<statnum;i++)
        {
            //ArrayList<Train>t1=t;
            trainState.add(t);
        }
    }
    public void debug1()
    {
        for(int k=0;k<trainState.get(0).size();k++)
        {
            System.out.println(trainState.get(0).get(k).nameID);
            for(int i=0;i<28;i++)
            {
                System.out.println("STATION ID: "+(i+1));
                trainState.get(i).get(k).DisplayCars();
                //pressEnterToContinue();
            }
        }
        
        
    }
    private void pressEnterToContinue()
    { 
           System.out.println("Press Enter key to continue...");
           try
           {
               System.in.read();
           }  
           catch(Exception e)
           {}  
    }
}
