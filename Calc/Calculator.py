
HOURS_WORKED = 35
PAY_RATE = 7.25
TOTAL_PAY = (HOURS_WORKED * PAY_RATE)

print(TOTAL_PAY)

def ovetime_pay(HOURS_WORKED, PAY_RATE, TOTAL_PAY):

    #Enter function if employee has over 40 hours
    if (HOURS_WORKED > 40):
        #Find OT
        overtime = (HOURS_WORKED - 40)
        #40 hours of 7.25 is 290 + 1.5 per hour of OT
        ((PAY_RATE * 1.5) * overtime) = TOTAL_PAY + 290
        return TOTAL_PAY


    else:
        return(1)
