
public class GeneratedReservation extends Reservation{
    private void RollTheDice()
    {
        
        int randIn=0;
        int randOut=0;
        int stat1=0;
        int stat2=0;
        do{
            randIn=rand.nextInt(239);
            randOut=rand.nextInt(220); 
            stat1=sbase.entryArray[randIn];
            stat2=sbase.exitArray[randOut];
        }while(stat1==stat2||randIn>=randOut);// NOT(stat1!=stat2&&randIN<randOut)

        //System.out.printf("RAND: %d %d \n",randIn, randOut);
        //System.out.printf("STAT: %d %d \n",stat1, stat2);
        entryStation=sbase.stationID[stat1-1];
        exitStation=sbase.stationID[stat2-1];
        //System.out.println(/*"RTD: "+entryStation+" "+exitStation+"\n"+*/sbase.stationNames[entryStation-1]+" to "+sbase.stationNames[exitStation-1]+"\n");
        //cos tu nie dziala
        int tries=0;
        int randWagon=0;
        int randSeat=0;
        do{
            randWagon=rand.nextInt(srs.trainState.get(0).get(trainID).nofWagons);
            randSeat=rand.nextInt(srs.trainState.get(0).get(trainID).TCs[randWagon].nofseats);
            tries++;
            //System.out.print(tries+" ");
        }while(srs.trainState.get(0).get(trainID).TCs[randWagon].seats[randSeat].IsOccupied());
       
            seat=randSeat;
            wagon=randWagon;
            //System.out.printf("wagon %d seat %d from station %d to %d\n",wagon+1,seat+1,entryStation,exitStation);
            // System.out.println("entrystat "+entryStation);
            for(int i=entryStation-1;i<=exitStation-1;i++)
            {
                //System.out.println(i);
                srs.trainState.get(i).get(trainID).TCs[wagon].seats[seat].ChangeOccupancy();
            }
            //srs.TCs[wagon].seats[seat].ChangeOccupancy();
        
    }
    public GeneratedReservation(StationResState s,int id)
    {
        trainID=id;
        srs=s;
        RollTheDice();
    }
    
    

}
