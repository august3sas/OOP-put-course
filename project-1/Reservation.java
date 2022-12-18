
import java.util.Random;
public class Reservation{
    protected Train assignedTrain;
    public int entryStation;
    public int exitStation;
    protected StationBase sbase=new StationBase();
    protected Random rand=new Random();
    protected int seat;
    protected int wagon;
    protected int trainID;//Train.codeID; 
    protected StationResState srs; 
    public Train WithNewReservation()
    {
        return assignedTrain;
    }
    public StationResState StatesWithNewReservation()
    {
        return srs;
    }
    protected boolean NotOccupiedAnytime(int trainindex,int wag,int sea,int statBegin,int statEnd)
    {
        for(int i=statBegin-1;i<=statEnd-1;i++)
        {
            if(srs.trainState.get(i).get(trainindex).TCs[wag].seats[sea].IsOccupied())return false;
        }
        return true;
    }
    
}