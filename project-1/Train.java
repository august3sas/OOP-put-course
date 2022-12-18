
public class Train {
    public int codeID=0;
    public String nameID="";
    public int nofWagons;
    public Traincar TCs[];
    public String tp;
    public int from;
    public int to;
    public int allPossibleSeats;
    public Train(int c, String n, String type,int fr, int t,int nw)
    {
        tp=type;
        codeID=c;
        nameID=n;
        from=fr;
        t=to;
        nofWagons=nw;
        TCs=new Traincar[nw];
        for(int i=0;i<nofWagons;i++)
        {
            TCs[i]=new Traincar(tp);
        }
        GenerateCarNums();
        allPossibleSeats=nofWagons*TCs[0].nofseats;
    }
    private void GenerateCarNums()
    {
        for(int i=0;i<nofWagons;i++)
        {
            TCs[i].tcID=i+1;
        }
    }
    public void DisplayCars()
    {
        for(int i=0;i<nofWagons;i++)
        {
            System.out.println("WAGON NR: "+TCs[i].tcID);
            TCs[i].DisplaySeats();
            System.out.println("\n----------------------------------------------\n");
        }
    }
    
}
