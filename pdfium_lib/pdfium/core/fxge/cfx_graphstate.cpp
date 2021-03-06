// Copyright 2016 PDFium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Original code copyright 2014 Foxit Software Inc. http://www.foxitsoftware.com

#include "core/fxge/cfx_graphstate.h"

#include "core/fpdfapi/parser/cpdf_array.h"

CFX_GraphState::CFX_GraphState() {}

CFX_GraphState::CFX_GraphState(const CFX_GraphState& that)
    : m_Ref(that.m_Ref) {}

CFX_GraphState::~CFX_GraphState() {}

void CFX_GraphState::Emplace() {
  m_Ref.Emplace();
}

void CFX_GraphState::SetLineDash(CPDF_Array* pArray, float phase, float scale) {
  CFX_GraphStateData* pData = m_Ref.GetPrivateCopy();
  pData->m_DashPhase = phase * scale;
  pData->m_DashArray.resize(pArray->size());
  for (size_t i = 0; i < pArray->size(); i++)
    pData->m_DashArray[i] = pArray->GetNumberAt(i) * scale;
}

float CFX_GraphState::GetLineWidth() const {
  return m_Ref.GetObject() ? m_Ref.GetObject()->m_LineWidth : 1.f;
}

void CFX_GraphState::SetLineWidth(float width) {
  m_Ref.GetPrivateCopy()->m_LineWidth = width;
}

CFX_GraphStateData::LineCap CFX_GraphState::GetLineCap() const {
  return m_Ref.GetObject() ? m_Ref.GetObject()->m_LineCap
                           : CFX_GraphStateData::LineCapButt;
}
void CFX_GraphState::SetLineCap(CFX_GraphStateData::LineCap cap) {
  m_Ref.GetPrivateCopy()->m_LineCap = cap;
}

CFX_GraphStateData::LineJoin CFX_GraphState::GetLineJoin() const {
  return m_Ref.GetObject() ? m_Ref.GetObject()->m_LineJoin
                           : CFX_GraphStateData::LineJoinMiter;
}

void CFX_GraphState::SetLineJoin(CFX_GraphStateData::LineJoin join) {
  m_Ref.GetPrivateCopy()->m_LineJoin = join;
}

float CFX_GraphState::GetMiterLimit() const {
  return m_Ref.GetObject() ? m_Ref.GetObject()->m_MiterLimit : 10.f;
}

void CFX_GraphState::SetMiterLimit(float limit) {
  m_Ref.GetPrivateCopy()->m_MiterLimit = limit;
}
