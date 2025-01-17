#ifndef TRACKBASEHISTORIC_SVTXTRACKMAPV2_H
#define TRACKBASEHISTORIC_SVTXTRACKMAPV2_H

#include "SvtxTrack.h"
#include "SvtxTrackMap.h"

#include <cstddef>        // for size_t
#include <iostream>        // for cout, ostream

class PHObject;

class SvtxTrackMap_v2 : public SvtxTrackMap
{
 public:
  SvtxTrackMap_v2();
  SvtxTrackMap_v2(const SvtxTrackMap_v2& trackmap);
  SvtxTrackMap_v2& operator=(const SvtxTrackMap_v2& trackmap);
  ~SvtxTrackMap_v2() override;

  void identify(std::ostream& os = std::cout) const override;
  // cppcheck-suppress virtualCallInConstructor
  void Reset() override;
  int isValid() const override { return 1; }
  PHObject* CloneMe() const override { return new SvtxTrackMap_v2(*this); }

  bool empty() const override{ return _map.empty(); }
  size_t size() const override { return _map.size(); }
  size_t count(unsigned int idkey) const override{ return _map.count(idkey); }
  void clear() override { Reset(); }

  const SvtxTrack* get(unsigned int idkey) const override;
  SvtxTrack* get(unsigned int idkey) override;
  SvtxTrack* insert(const SvtxTrack* track) override;
  SvtxTrack* insertWithKey(const SvtxTrack* track, unsigned int index) override;
  size_t erase(unsigned int idkey) override
  {
    delete _map[idkey];
    return _map.erase(idkey);
  }

  ConstIter begin() const override { return _map.begin(); }
  ConstIter find(unsigned int idkey) const override { return _map.find(idkey); }
  ConstIter end() const override { return _map.end(); }

  Iter begin() override { return _map.begin(); }
  Iter find(unsigned int idkey) override { return _map.find(idkey); }
  Iter end() override { return _map.end(); }

 private:
  TrackMap _map;

  ClassDefOverride(SvtxTrackMap_v2, 2);
};

#endif
