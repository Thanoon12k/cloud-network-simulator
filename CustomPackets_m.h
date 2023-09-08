//
// Generated file, do not edit! Created by opp_msgtool 6.0 from CustomPackets.msg.
//

#ifndef __CUSTOMPACKETS_M_H
#define __CUSTOMPACKETS_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

class Image;
/**
 * Class generated from <tt>CustomPackets.msg:3</tt> by opp_msgtool.
 * <pre>
 * packet Image
 * {
 *     int uniqueID;
 *     string content;
 * }
 * </pre>
 */
class Image : public ::omnetpp::cPacket
{
  protected:
    int uniqueID = 0;
    omnetpp::opp_string content;

  private:
    void copy(const Image& other);

  protected:
    bool operator==(const Image&) = delete;

  public:
    Image(const char *name=nullptr, short kind=0);
    Image(const Image& other);
    virtual ~Image();
    Image& operator=(const Image& other);
    virtual Image *dup() const override {return new Image(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getUniqueID() const;
    virtual void setUniqueID(int uniqueID);

    virtual const char * getContent() const;
    virtual void setContent(const char * content);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Image& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Image& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline Image *fromAnyPtr(any_ptr ptr) { return check_and_cast<Image*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __CUSTOMPACKETS_M_H

