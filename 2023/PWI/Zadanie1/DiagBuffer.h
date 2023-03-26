#ifndef DIAGBUFFER_H_INCLUDED
#define DIAGBUFFER_H_INCLUDED

class Program {
public:
    static void buff_in(const std::string &message)
    {
    #ifdef DIAGBUFFER_H_INCLUDED
        buffer_ += message;
    #endif
    }
    static void przekazanie_do_bufora(const std::string& filename)
    {
    #ifdef DIAGBUFFER_H_INCLUDED
        std::ofstream outfile;
        outfile.open(filename, std::ios_base::app);
        if (outfile.is_open()) {
            outfile << buffer_;
            buffer_.clear();
        }
        outfile.close();
    #endif // DIAG_ENABLE
    }
    static void F1(const std::string &filename, int indents)
    {
    #ifdef DIAGBUFFER_H_INCLUDED
        std::ofstream outfile;
        outfile.open(filename, std::ios_base::app);
        if(outfile.is_open())
        {
            for(int i=0;i<indents;i++)
                outfile << "\t";
        }
        outfile.close();
    #endif // DIAG_ENABLE
    }
    static void F2(const std::string &filename, int indents)
    {

    #ifdef DIAGBUFFER_H_INCLUDED
        std::ofstream outfile;
        outfile.open(filename, std::ios_base::app);
        if(outfile.is_open())
        {
            for(int i=0;i<indents;i++)
                outfile << "";
        }
        outfile.close();
    #endif // DIAG_ENABLE
    }
private:
    static int indents;
    static std::string buffer_;
};

std::string Program::buffer_ = "";

#endif // DIAGBUFFER_H_INCLUDED
