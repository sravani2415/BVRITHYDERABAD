/* Program on Creat*/
#include &lt;stdio.h&gt;
#include &lt;sys/types.h&gt; /* defines types used by sys/stat.h */
#include &lt;sys/stat.h&gt; /* defines S_IREAD &amp; S_IWRITE */
int main()
{
int fd;

fd = creat(&quot;datafile.dat&quot;, S_IREAD | S_IWRITE);
if (fd == -1)
printf(&quot;Error in opening datafile.dat\n&quot;);
else
{
printf(&quot;datafile.dat opened for read/write access\n&quot;);
printf(&quot;datafile.dat is currently empty\n&quot;);
}
close(fd);
exit (0);
}
