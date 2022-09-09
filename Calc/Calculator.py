
HOURS_WORKED = 39
PAY_RATE = 7.25
TOTAL_PAY = (HOURS_WORKED * PAY_RATE)

def overtime_pay(HOURS_WORKED, PAY_RATE, TOTAL_PAY):

    #Enter function if employee has over 40 hours
    if (HOURS_WORKED > 40):
        #Find OT
        overtime = (HOURS_WORKED - 40)
        #40 hours of 7.25 is 290 + 1.5 per hour of OT
        ((PAY_RATE * 1.5) * overtime + 290) == TOTAL_PAY
        return TOTAL_PAY

    else:
        return(1)




overtime_pay(HOURS_WORKED, PAY_RATE, TOTAL_PAY)

print(TOTAL_PAY)


