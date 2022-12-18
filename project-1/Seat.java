
public class Seat{
    
    private boolean status;
    public int seatNumber;

    public Seat()
    {
        status=false;
        seatNumber=0;
        //System.out.println("siedznie");
    }
    public int CheckOccupancy()
    {
        if(status)return 1;else return 0;
    }
    public boolean IsOccupied()
    {
        return status;
    }
    public void ChangeOccupancy()
    {
        status=true;
    }
    
}
