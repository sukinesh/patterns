^j::
b=34
loop,12
{
send,{shift down}{right 998}{shift up}
send,{ctrl down}x{ctrl up}
sleep,1000
send,{ctrl down}{shift down}n{shift up}{ctrl up}
sleep,1000
send,%b%
sleep,1000
send,{enter}
sleep,500
send,{enter}
winactivate,%b%
WinWaitActive,%b%
send,{ctrl down}v{ctrl up}
sleep,25000
send,{backspace}
sleep,3000
send,{right}
b+=1
}
Return